"""縦型15〜20秒の図解動画エンジン。声(say)＋効果音(ffmpeg合成)＋PIL描画。
場面は dict(voice, sub, code, draw, events, min_len) で渡す。draw(c, tl) の tl は場面開始からの秒。"""
import math, subprocess
from functools import lru_cache
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

W, H, FPS = 1080, 1920, 30
BG, FG, MUTED, LINE = (247, 246, 241), (28, 32, 30), (120, 126, 120), (214, 214, 205)
ACC, ACC_SOFT = (14, 122, 92), (214, 238, 228)
WARN, WARN_SOFT = (180, 83, 26), (251, 233, 220)
CODE_BG, GHOST = (236, 236, 228), (170, 176, 170)
MODES = {  # 塗り, 枠, 文字
    "idle": (ACC_SOFT, ACC, FG), "now": (ACC, ACC, BG), "done": ((228, 232, 226), LINE, MUTED),
    "warn": (WARN_SOFT, WARN, FG), "hot": (WARN, WARN, BG), "blank": (BG, LINE, MUTED),
}
VOICE, RATE = "Kyoko", 175
FONT_FILES = {"J": "/System/Library/Fonts/ヒラギノ角ゴシック W6.ttc",
              "J3": "/System/Library/Fonts/ヒラギノ角ゴシック W3.ttc",
              "M": "/System/Library/Fonts/Menlo.ttc"}

@lru_cache(None)
def F(kind, size): return ImageFont.truetype(FONT_FILES[kind], size)

def ease(x):
    x = max(0.0, min(1.0, x)); return 1 - (1 - x) ** 3
def prog(t, a, d): return ease((t - a) / d)

class Canvas:
    def __init__(s):
        s.im = Image.new("RGB", (W, H), BG); s.d = ImageDraw.Draw(s.im)
    def text(s, xy, t, f, fill, anchor="mm"): s.d.text(xy, t, font=f, fill=fill, anchor=anchor)
    def cell(s, cx, cy, w, h, label, mode="idle", f=None, idx=None):
        fill, line, col = MODES[mode]
        s.d.rounded_rectangle([cx - w / 2, cy - h / 2, cx + w / 2, cy + h / 2], radius=10, fill=fill, outline=line, width=4)
        if label: s.text((cx, cy), label, f or F("M", 42), col)
        if idx is not None: s.text((cx, cy + h / 2 + 28), str(idx), F("M", 26), MUTED)
    def row(s, items, cy, cw=70, gap=8, modes=None, cx=W / 2, h=None, f=None, idx=False):
        """items の要素が None か、modes が 'hide' のものは描かない。各セルの中心 x を返す。"""
        n = len(items); x0 = cx - (n * cw + (n - 1) * gap) / 2 + cw / 2; xs = []
        for i, it in enumerate(items):
            x = x0 + i * (cw + gap); xs.append(x)
            m = modes[i] if modes else "idle"
            if it is None or m == "hide": continue
            s.cell(x, cy, cw, h or cw * 1.2, it, m, f, i if idx else None)
        return xs
    def label(s, x, y, t, col=MUTED, anchor="lm"): s.text((x, y), t, F("J", 36), col, anchor)
    def chip(s, y, label, kind):
        col, soft = (ACC, ACC_SOFT) if kind == "ok" else (WARN, WARN_SOFT)
        s.d.rounded_rectangle([140, y, W - 140, y + 110], radius=55, fill=soft, outline=col, width=5)
        s.text((W / 2, y + 55), label, F("J", 48), col)
    def arrow(s, x0, y0, x1, y1, col=ACC, w=8):
        s.d.line([(x0, y0), (x1, y1)], fill=col, width=w)
        ang = math.atan2(y1 - y0, x1 - x0)
        for sg in (1, -1):
            a = ang + math.pi + sg * 0.5
            s.d.line([(x1, y1), (x1 + 28 * math.cos(a), y1 + 28 * math.sin(a))], fill=col, width=w)

def fit(text, kind, size, lo, maxw, multiline=False):
    while size > lo:
        f = F(kind, size)
        if max(f.getlength(l) for l in text.split("\n")) <= maxw: break
        size -= 2
    return F(kind, size)

# --- 効果音 ---
SFX = {
    "pop":  "aevalsrc='0.7*sin(2*PI*(520+900*t)*t)*exp(-t*38)':d=0.22:s=44100",
    "tick": "aevalsrc='0.5*sin(2*PI*1800*t)*exp(-t*70)':d=0.12:s=44100",
    "ding": "aevalsrc='0.6*sin(2*PI*1320*t)*exp(-t*5)+0.3*sin(2*PI*1980*t)*exp(-t*7)':d=1.0:s=44100",
}
def make_sfx(d):
    d = Path(d); d.mkdir(parents=True, exist_ok=True)
    for name, src in SFX.items():
        subprocess.run(["ffmpeg", "-y", "-loglevel", "error", "-f", "lavfi", "-i", src, str(d / f"{name}.wav")], check=True)

def probe(p):
    r = subprocess.run(["ffprobe", "-v", "error", "-show_entries", "format=duration", "-of", "csv=p=0", str(p)],
                       capture_output=True, text=True)
    return float(r.stdout)

def build(slug, title, scenes, outdir, sfx_dir):
    out = Path(outdir) / slug; out.mkdir(parents=True, exist_ok=True)
    # 声 → 場面の長さ
    starts, lens, t = [], [], 0.3
    for i, sc in enumerate(scenes):
        f = out / f"v{i}.aiff"
        subprocess.run(["say", "-v", VOICE, "-r", str(RATE), "-o", str(f), sc["voice"]], check=True)
        L = max(0.25 + probe(f) + 0.6, sc.get("min_len", 0))
        starts.append(t); lens.append(L); t += L
    total = t + 0.4
    # 音を1本に
    inputs, filt, labels = [], [], []
    def add(path, at, vol):
        i = len(inputs) // 2
        inputs.extend(["-i", str(path)])
        filt.append(f"[{i}:a]volume={vol},adelay={int(at*1000)}|{int(at*1000)}[a{i}]"); labels.append(f"[a{i}]")
    for i, sc in enumerate(scenes):
        add(out / f"v{i}.aiff", starts[i] + 0.25, 1.0)
        for (et, name) in sc.get("events", []): add(Path(sfx_dir) / f"{name}.wav", starts[i] + et, 0.35)
    mix = "".join(labels) + f"amix=inputs={len(labels)}:normalize=0,alimiter=limit=0.95,apad=whole_dur={total}[a]"
    subprocess.run(["ffmpeg", "-y", "-loglevel", "error", *inputs, "-filter_complex", ";".join(filt) + ";" + mix,
                    "-map", "[a]", "-t", str(total), str(out / "audio.wav")], check=True)

    def frame(t):
        c = Canvas()
        c.text((72, 120), f"C++ 図解 ・ {title}", F("J3", 34), MUTED, "lm")
        c.d.line([(72, 180), (W - 72, 180)], fill=LINE, width=3)
        idx = max([i for i, s in enumerate(starts) if t >= s], default=-1)
        if idx >= 0:
            sc, tl = scenes[idx], t - starts[idx]
            if sc.get("code"):
                c.d.rounded_rectangle([72, 300, W - 72, 420], radius=14, fill=CODE_BG)
                c.text((110, 360), sc["code"], fit(sc["code"], "M", 50, 26, W - 220), FG, "lm")
            sc["draw"](c, tl)
            f = fit(sc["sub"], "J", 78, 46, W - 120)
            c.d.multiline_text((W / 2, 1500), sc["sub"], font=f, fill=FG, anchor="ma", align="center", spacing=22)
        c.d.rectangle([0, H - 14, W * min(t / total, 1), H], fill=ACC)
        return c.im

    enc = subprocess.Popen(["ffmpeg", "-y", "-loglevel", "error", "-f", "rawvideo", "-pix_fmt", "rgb24", "-s", f"{W}x{H}",
                            "-r", str(FPS), "-i", "-", "-i", str(out / "audio.wav"), "-c:v", "libx264", "-pix_fmt", "yuv420p",
                            "-crf", "20", "-c:a", "aac", "-b:a", "160k", "-shortest", str(Path(outdir) / f"{slug}.mp4")],
                           stdin=subprocess.PIPE)
    for n in range(int(total * FPS)): enc.stdin.write(frame(n / FPS).tobytes())
    enc.stdin.close(); enc.wait()
    for i in range(len(scenes)): frame(starts[i] + lens[i] * 0.8).save(out / f"snap{i}.png")
    return slug, round(total, 1)
