#!/usr/bin/env python3
"""string / vector 6問の解説動画を作る。
使い方: python3 problems.py <出力フォルダ> [13 09 10 12 15 42]   （省略時は全部）"""
import sys
from multiprocessing import Pool
from pathlib import Path
from engine import *

M = lambda n: F("M", n)
JP = lambda n: F("J", n)
vis = lambda s: "␣" if s == " " else s

# ───────── CPE49-13 TeX Quotes ─────────
def p13():
    TEXT = '"Hi," he "ok"'; N = len(TEXT); STEP, S0 = 0.27, 0.5
    def res(k):
        out, opn = "", True
        for ch in TEXT[:k]:
            if ch == '"': out += "``" if opn else "''"; opn = not opn
            else: out += ch
        return out, opn
    FULL = res(N)[0]
    def cells(c, modes):
        c.label(60, 640, "入力"); c.label(60, 880, "出力")
        c.row([vis(ch) for ch in TEXT], 742, cw=64, gap=6, modes=modes, h=84, f=M(42), idx=True)
    def A(c, tl):
        cells(c, ["idle" if tl > 0.3 else "hide"] * N)
        if tl > 1.4: c.text((W / 2, 960), FULL, M(62), ACC)
    def B(c, tl):
        cells(c, ["warn" if ch == '"' else "idle" for ch in TEXT]); c.text((W / 2, 960), FULL, M(62), GHOST)
        n = sum(1 for j in range(3) if tl >= 0.6 + 0.9 * j)
        if n: c.chip(1180, "次の \" は  開き  ``" if n % 2 else "次の \" は  閉じ  ''", "ok" if n % 2 else "warn")
    def C(c, tl):
        k = max(0, min(N, int((tl - S0) / STEP) + 1)) if tl >= S0 else 0
        cells(c, ["now" if i == k - 1 else "done" if i < k - 1 else "idle" for i in range(N)])
        o, opn = res(k); c.text((W / 2, 960), o, M(62), ACC)
        c.chip(1180, "次の \" は  開き  ``" if opn else "次の \" は  閉じ  ''", "ok" if opn else "warn")
    def D(c, tl):
        cells(c, ["warn" if ch == " " else "done" for ch in TEXT]); c.text((W / 2, 960), FULL, M(62), ACC)
        c.chip(1180, "次の \" は  開き  ``", "ok")
        if tl > 0.8: c.text((W / 2, 1110), "空白も改行も 1 文字として出力", JP(36), WARN)
    return "13", "CPE49-13 TeX Quotes", [
        dict(voice="ダブルクォートを、開きと閉じの形に、交互に置き換えます。", sub="\" を 開き・閉じの形に\n交互に置き換える",
             code="// input -> output", draw=A, events=[(0.3, "pop"), (1.4, "ding")], min_len=3.8),
        dict(voice="覚えるのは一つだけ。次のダブルクォートが、開きか閉じかです。", sub="覚えるのは 1 つだけ\n次の \" は開きか閉じか",
             code="bool open = true;", draw=B, events=[(0.6 + 0.9 * j, "tick") for j in range(3)], min_len=3.6),
        dict(voice="一文字ずつ読んで、ダブルクォートが来たら置き換えます。", sub="1 文字ずつ読んで\n\" が来たら置き換える",
             code="while (cin.get(c)) { ... }", draw=C,
             events=[(S0 + k * STEP, "pop" if ch == '"' else "tick") for k, ch in enumerate(TEXT)], min_len=S0 + N * STEP + 0.5),
        dict(voice="空白も改行も、そのまま出すので、シーイン、ゲットで読みます。", sub="空白も改行もそのまま\ncin.get(c) で読む",
             code="cin.get(c)  // not cin >> c", draw=D, events=[(0.5, "tick"), (0.8, "tick"), (1.8, "ding")], min_len=3.2),
    ]

# ───────── CPE49-09 Decode the Mad man ─────────
def p09():
    R1, R2 = "qwertyuiop[]", "asdfghjkl;'"
    DEC = {"k": "h", "[": "o", "r": "w", " ": " ", "d": "a", "y": "r", "t": "e"}
    def kb(c, m1=None, m2=None, idx=False):
        x1 = c.row(list(R1), 640, cw=70, gap=8, modes=m1, h=84, f=M(40), idx=idx)
        x2 = c.row(list(R2), 800, cw=70, gap=8, modes=m2, h=84, f=M(40), cx=W / 2 + 39, idx=idx)
        return x1, x2
    def A(c, tl):
        m2 = ["idle"] * 11
        if tl > 1.0: m2[7] = "hot"
        if tl > 1.6: m2[5] = "now"
        x1, x2 = kb(c, None, m2)
        if tl > 1.6:
            c.arrow(x2[7], 890, x2[5], 890); c.text(((x2[7] + x2[5]) / 2, 940), "2 つ左", JP(40), ACC)
        if tl > 2.2: c.text((W / 2, 1120), "k -> h", M(80), ACC)
    def B(c, tl):
        m2 = ["idle"] * 11
        if tl > 0.6: m2[7] = "hot"
        if tl > 1.5: m2[5] = "now"
        kb(c, None, m2, idx=True)
        if tl > 0.6: c.text((W / 2, 1060), "i = t.find('k')   // 7", M(44), WARN)
        if tl > 1.5: c.text((W / 2, 1150), "t[i - 2]          // 'h'", M(44), ACC)
    def C(c, tl):
        steps = [("k", 2, 7, 5), ("[", 1, 10, 8), ("r", 1, 3, 1)]
        i = min(2, int((tl - 0.4) / 1.0)) if tl >= 0.4 else -1
        m1, m2 = ["idle"] * 12, ["idle"] * 11
        if i >= 0:
            _, row, s, d = steps[i]
            (m1 if row == 1 else m2)[s] = "hot"; (m1 if row == 1 else m2)[d] = "now"
        kb(c, m1, m2, idx=True)
        c.row(list("k[r"), 1010, cw=80, gap=12, modes=["now" if j == i else "idle" for j in range(3)], h=96, f=M(48))
        c.label(60, 1010, "入力", anchor="lm")
        c.row(list("how")[: i + 1] if i >= 0 else [], 1190, cw=80, gap=12, modes=["idle"] * 3, h=96, f=M(48), cx=W / 2 - (2 - i) * 46)
    def D(c, tl):
        s = "k[r dyt"
        c.label(60, 560, "入力")
        c.row([vis(ch) for ch in s], 660, cw=80, gap=10, modes=["warn" if ch == " " else "idle" for ch in s], h=100, f=M(48))
        k = max(0, min(7, int((tl - 0.4) / 0.4) + 1)) if tl >= 0.4 else 0
        c.label(60, 860, "出力")
        out = [vis(DEC[ch]) for ch in s]
        c.row([out[i] if i < k else None for i in range(7)], 960, cw=80, gap=10,
              modes=["warn" if s[i] == " " else "now" if i == k - 1 else "idle" for i in range(7)], h=100, f=M(48))
        if tl > 3.0: c.text((W / 2, 1180), "表にない文字は そのまま出力", JP(40), WARN)
    return "09", "CPE49-09 Decode the Mad man", [
        dict(voice="キーボードで、二つ左のキーの文字に直します。", sub="キーボードで\n2 つ左の文字に直す",
             code="// 2 keys to the left", draw=A, events=[(1.0, "tick"), (1.6, "pop"), (2.2, "ding")], min_len=3.8),
        dict(voice="全部のキーを並べた表を作って、文字の位置を探し、二つ前を取ります。", sub="表の中で位置を探して\n2 つ前を取る",
             code="t[t.find(c) - 2]", draw=B, events=[(0.6, "tick"), (1.5, "pop")], min_len=3.6),
        dict(voice="ケーはエイチ、左かっこはオー、アールはダブリューになります。", sub="k → h   [ → o   r → w",
             code="for (char c : s) { ... }", draw=C, events=[(0.4 + 1.0 * j, "pop") for j in range(3)], min_len=4.2),
        dict(voice="空白は表にないので、そのまま出力します。", sub="表にない文字は\nそのまま出す",
             code="not in table -> keep c", draw=D, events=[(0.4 + 0.4 * j, "tick") for j in range(7)] + [(3.0, "ding")], min_len=3.8),
    ]

# ───────── CPE49-10 Summing Digits ─────────
def p10():
    DIG = "1234567892"
    def digits(c, modes):
        c.row(list(DIG), 700, cw=80, gap=8, modes=modes, h=110, f=M(54))
    def A(c, tl):
        digits(c, ["idle" if tl > 0.3 else "hide"] * 10)
        if tl > 1.4: c.text((W / 2, 960), "全部の桁を足す", JP(48), ACC)
        if tl > 2.4: c.text((W / 2, 1060), "一桁になるまで繰り返す", JP(48), ACC)
    def B(c, tl):
        k = max(0, min(10, int((tl - 0.4) / 0.3) + 1)) if tl >= 0.4 else 0
        digits(c, ["now" if i == k - 1 and k < 10 else "done" if i < k else "idle" for i in range(10)])
        s = sum(int(ch) for ch in DIG[:k])
        c.text((W / 2, 980), f"sum = {s}", M(96), WARN if k == 10 else ACC)
    def C(c, tl):
        xs = [W / 2 - 330, W / 2, W / 2 + 330]
        for j, (v, a) in enumerate([("47", 0.3), ("11", 1.3), ("2", 2.3)]):
            if tl > a: c.cell(xs[j], 800, 220, 170, v, "hot" if v == "2" else "idle", M(86))
        for j, (f_, a) in enumerate([("4+7", 1.0), ("1+1", 2.0)]):
            if tl > a:
                c.arrow(xs[j] + 120, 800, xs[j + 1] - 120, 800); c.text(((xs[j] + xs[j + 1]) / 2, 745), f_, M(40), ACC)
    def D(c, tl):
        for y, s, a, col in [(800, "'7' = 55", 0.4, ACC), (920, "'0' = 48", 1.2, ACC), (1060, "55 - 48 = 7", 2.0, WARN)]:
            if tl > a: c.text((W / 2, y), s, M(84), col)
    return "10", "CPE49-10 Summing Digits", [
        dict(voice="全部の桁を足して、一桁になるまで繰り返します。", sub="桁を全部足して\n一桁になるまで繰り返す",
             code="n = 1234567892", draw=A, events=[(0.3, "pop"), (1.4, "tick"), (2.4, "tick")], min_len=3.8),
        dict(voice="一二三四五六七八九二を足すと、四十七になります。", sub="1+2+3+…+2 = 47",
             code="sum += c - '0';", draw=B, events=[(0.4 + 0.3 * i, "tick") for i in range(10)] + [(3.5, "ding")], min_len=4.4),
        dict(voice="四十七は、四足す七で十一。十一は、一足す一で、二になります。", sub="47 → 11 → 2\n一桁になったら終わり",
             code="while (n >= 10) n = f(n);", draw=C, events=[(0.3, "pop"), (1.3, "pop"), (2.3, "ding")], min_len=3.8),
        dict(voice="数字は文字として読みます。文字引く、文字のゼロで、数に直せます。", sub="文字 − '0' で\n数字に直す",
             code="n += c - '0';", draw=D, events=[(0.4, "tick"), (1.2, "tick"), (2.0, "ding")], min_len=3.6),
    ]

# ───────── CPE49-12 Rotating Sentences ─────────
def p12():
    L1, L2, CX = "ABC", "xy", W / 2 + 60
    OUT = [(L2[j] if j < len(L2) else " ") + L1[j] for j in range(3)]
    def inp(c, tl=99, hi=None, blank_warn=False):
        c.label(60, 620, "1行目"); c.label(60, 740, "2行目")
        m1 = [("now" if hi == j else "idle") if tl > 0.3 else "hide" for j in range(3)]
        m2 = [("now" if hi == j else "idle") if tl > 0.6 else "hide" for j in range(2)] + ["warn" if blank_warn else "blank"]
        c.row(list(L1), 620, cw=90, gap=10, modes=m1, cx=CX, h=100, f=M(50))
        c.row(list(L2) + [""], 740, cw=90, gap=10, modes=m2, cx=CX, h=100, f=M(50))
    def outrows(c, shown, hi=None, pad_warn=False):
        c.label(60, 930, "出力")
        for j in range(3):
            if j >= shown: continue
            modes = ["now" if hi == j else "idle"] * 2
            if pad_warn and j == 2: modes[0] = "warn"
            c.row([vis(ch) for ch in OUT[j]], 1020 + j * 120, cw=90, gap=10, modes=modes, cx=CX, h=100, f=M(50))
    def A(c, tl):
        inp(c, tl); outrows(c, 3 if tl > 1.8 else 0)
    def B(c, tl):
        i = min(2, int((tl - 0.4) / 1.0)) if tl >= 0.4 else -1
        inp(c, hi=i if i >= 0 else None); outrows(c, i + 1, hi=i)
    def C(c, tl):
        inp(c, blank_warn=tl > 0.5); outrows(c, 3, pad_warn=tl > 0.5)
        if tl > 1.2: c.text((W / 2, 1430), "足りない所は ␣ で埋める", JP(40), WARN)
    def D(c, tl):
        for j, (v, nm) in enumerate([("3", "1行目の長さ"), ("2", "2行目の長さ")]):
            x = W / 2 + (-170 if j == 0 else 170)
            if tl > 0.4 + 0.5 * j: c.cell(x, 800, 150, 150, v, "idle", M(72)); c.text((x, 920), nm, JP(32), MUTED)
        if tl > 1.6: c.text((W / 2, 1100), "maxLen = 3", M(84), WARN)
    return "12", "CPE49-12 Rotating Sentences", [
        dict(voice="文を九十度回して、縦に出力します。", sub="文を 90 度回して\n縦に出力する",
             code="// rotate 90 degrees", draw=A, events=[(0.3, "pop"), (0.6, "pop"), (1.8, "ding")], min_len=3.6),
        dict(voice="縦一列が、出力の一行になります。最後の文から順に並べます。", sub="縦 1 列が出力の 1 行\n最後の文が先頭",
             code="for (j = 0; j < maxLen; j++)", draw=B, events=[(0.4 + 1.0 * j, "pop") for j in range(3)], min_len=3.8),
        dict(voice="短い文は、足りない文字を空白で埋めます。", sub="足りない文字は\n空白で埋める",
             code="else cout << ' ';", draw=C, events=[(0.5, "tick"), (1.2, "ding")], min_len=3.4),
        dict(voice="先に全部の行を読んで、一番長い長さを求めておきます。", sub="先に一番長い行の\n長さを求める",
             code="maxLen = max(maxLen, s.size());", draw=D, events=[(0.4, "tick"), (0.9, "tick"), (1.6, "ding")], min_len=3.6),
    ]

# ───────── CPE49-15 Jolly Jumpers ─────────
def p15():
    S1, S2 = [1, 4, 2, 3], [1, 4, 2, -1, 6]
    def state(seq, k):
        n = len(seq); diffs = [abs(seq[i + 1] - seq[i]) for i in range(n - 1)]
        seen, status = set(), []
        for d in diffs[:k]:
            ok = 1 <= d <= n - 1 and d not in seen
            status.append("now" if ok else "hot")
            if ok: seen.add(d)
        return diffs, status, seen
    def draw(c, seq, k_diff, k_seen, show_seen, missing=False):
        n = len(seq); diffs, st, _ = state(seq, k_diff)
        xs = c.row([str(v) for v in seq], 620, cw=100, gap=60, h=110, f=M(54))
        for i in range(min(k_diff, n - 1)):
            x = (xs[i] + xs[i + 1]) / 2
            c.text((x, 700), "|差|", JP(26), MUTED)
            c.cell(x, 770, 84, 80, str(diffs[i]), st[i], M(46))
        if show_seen:
            _, st2, seen = state(seq, k_seen)
            modes = ["now" if v in seen else ("warn" if missing and v == 1 else "blank") for v in range(1, n)]
            c.label(60, 940, "出た差 (seen)")
            c.row([str(v) for v in range(1, n)], 1030, cw=90, gap=14, modes=modes, h=100, f=M(48))
    def A(c, tl):
        k = max(0, min(3, int((tl - 1.0) / 0.7) + 1)) if tl >= 1.0 else 0
        if tl > 0.3: draw(c, S1, k, 0, False)
    def B(c, tl):
        k = max(0, min(3, int((tl - 0.6) / 0.7) + 1)) if tl >= 0.6 else 0
        draw(c, S1, 3, k, True)
    def C(c, tl):
        draw(c, S1, 3, 3, True)
        if tl > 0.6: c.text((W / 2, 1230), "Jolly", M(110), ACC)
    def D(c, tl):
        k = max(0, min(4, int((tl - 0.5) / 0.7) + 1)) if tl >= 0.5 else 0
        draw(c, S2, k, k, True, missing=tl > 3.4)
        if tl > 3.6: c.text((W / 2, 1230), "Not jolly", M(100), WARN)
    return "15", "CPE49-15 Jolly Jumpers", [
        dict(voice="隣どうしの差の絶対値が、一から、エヌ引く一まで、全部そろえば、ジョリーです。", sub="隣どうしの差が\n1〜n-1 全部そろえば Jolly",
             code="d = abs(a[i+1] - a[i]);", draw=A, events=[(0.3, "pop")] + [(1.0 + 0.7 * i, "tick") for i in range(3)], min_len=4.2),
        dict(voice="出てきた差に、印をつけていきます。ベクターブールで覚えます。", sub="出た差に印をつける\nvector<bool>",
             code="vector<bool> seen(n);", draw=B, events=[(0.6 + 0.7 * i, "pop") for i in range(3)], min_len=3.6),
        dict(voice="一から全部に印がつけば、ジョリーです。", sub="全部に印がつけば\nJolly",
             code="all seen[1..n-1] -> Jolly", draw=C, events=[(0.6, "ding")], min_len=3.0),
        dict(voice="二つ目の例は、三が重なって、七は範囲の外。ジョリーではありません。", sub="3 が重なり、7 は範囲外\nNot jolly",
             code="if (d < 1 || d >= n || seen[d])", draw=D, events=[(0.5 + 0.7 * i, "tick") for i in range(4)] + [(3.6, "pop")], min_len=5.0),
    ]

# ───────── CPE49-42 Train Swapping ─────────
def p42():
    arr = [4, 3, 2, 1]; steps = []; a = arr[:]
    for p in range(3):
        for j in range(3 - p):
            if a[j] > a[j + 1]:
                before = a[:]; a[j], a[j + 1] = a[j + 1], a[j]; steps.append((before, a[:], j))
    CW = dict(cw=120, gap=20, h=140, f=M(60))
    def cnt(c, n): c.text((W / 2, 1010), f"入れ替え  {n}  回", JP(64), WARN if n else MUTED)
    def A(c, tl):
        if tl < 1.0: v, m, n = [1, 3, 2], ["idle"] * 3, 0
        elif tl < 1.7: v, m, n = [1, 3, 2], ["idle", "hot", "hot"], 0
        else: v, m, n = [1, 2, 3], ["idle", "now", "now"], 1
        c.row([str(x) for x in v], 700, modes=m, **CW); cnt(c, n)
    def B(c, tl):
        i = int((tl - 0.4) / 0.55) if tl >= 0.4 else -1
        if i < 0: v, m, n = arr, ["idle"] * 4, 0
        elif i >= len(steps): v, m, n = [1, 2, 3, 4], ["done"] * 4, len(steps)
        else:
            ph = (tl - 0.4) % 0.55 < 0.25; b, af, j = steps[i]
            v, n = (b, i) if ph else (af, i + 1)
            m = ["idle"] * 4; m[j] = m[j + 1] = "hot" if ph else "now"
        c.row([str(x) for x in v], 700, modes=m, **CW); cnt(c, n)
    def C(c, tl):
        c.row(["1", "2", "3", "4"], 700, modes=["done"] * 4, **CW); cnt(c, 6)
        if tl > 0.8: c.text((W / 2, 1180), "Optimal train swapping", M(40), ACC); c.text((W / 2, 1240), "takes 6 swaps.", M(40), ACC)
    def D(c, tl):
        c.row([str(x) for x in arr], 700, modes=["idle"] * 4, **CW)
        for y, s, a in [(960, "a に L 個読み込む", 0.4), (1060, "隣を比べて 逆なら swap", 1.1), (1160, "cnt を 1 増やす", 1.8)]:
            if tl > a: c.text((W / 2, y), s, JP(44), ACC if y != 1160 else WARN)
    return "42", "CPE49-42 Train Swapping", [
        dict(voice="隣り合う二つだけを入れ替えて、順番に並べます。最少の回数が答えです。", sub="隣り合う 2 つだけ入れ替えて\n並べた回数を数える",
             code="swap(a[1], a[2]);", draw=A, events=[(1.0, "tick"), (1.7, "pop")], min_len=3.8),
        dict(voice="隣を比べて、逆なら入れ替える。これを繰り返します。", sub="隣を比べて\n逆なら入れ替える",
             code="if (a[j] > a[j+1])", draw=B,
             events=[(0.4 + 0.55 * i + 0.25, "pop") for i in range(len(steps))], min_len=0.4 + 0.55 * len(steps) + 0.6),
        dict(voice="入れ替えた回数を数えると、六回です。", sub="入れ替えた回数が\n答え (4 3 2 1 → 6 回)",
             code="cnt = 6;", draw=C, events=[(0.5, "ding")], min_len=3.2),
        dict(voice="プログラムでは、二重のループで隣を比べて、入れ替えるたびに数えます。", sub="二重ループで隣を比べ\n入れ替えるたび数える",
             code="swap(a[j], a[j+1]); cnt++;", draw=D, events=[(0.4, "tick"), (1.1, "tick"), (1.8, "ding")], min_len=3.8),
    ]

BUILDERS = {"13": p13, "09": p09, "10": p10, "12": p12, "15": p15, "42": p42}

def job(args):
    key, outdir = args
    slug, title, scenes = BUILDERS[key]()
    return build(f"cpe49-{slug}", title, scenes, outdir, Path(outdir) / "sfx")

if __name__ == "__main__":
    outdir = Path(sys.argv[1]); keys = sys.argv[2:] or list(BUILDERS)
    make_sfx(outdir / "sfx")
    with Pool(min(len(keys), 6)) as p:
        for slug, total in p.imap_unordered(job, [(k, str(outdir)) for k in keys]):
            print("done", slug, total, "s")
