#!/usr/bin/env python3
"""CPE 解答テストランナー

使い方:
  python3 tests/run.py CPE02                 # サンプル + エッジ + ランダム100件
  python3 tests/run.py CPE02 --n 5 --show    # ランダム5件の入出力を表示
  python3 tests/run.py CPE02 --only failed   # 前回落ちた入力だけ再実行
  python3 tests/run.py answers/CPE02.cpp     # パスを渡してもOK（Zed用）

ディレクトリ:
  answers/CPExx.cpp              解答
  answers/samples/CPExx.in/.out  サンプル（出力を照合）
  tests/edge/CPExx/*.in (.out)   手書きのエッジケース（.out があれば照合）
  tests/gen/CPExx.py             ランダム生成器 gen(r) -> str（無ければサンプルを変異させる）
  tests/brute/CPExx.cpp          愚直解（あればランダム入力で出力を比較）
  tests/failed/CPExx.in          最後に落ちた入力（自動保存）
"""
import argparse
import importlib.util
import random
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TESTS = ROOT / "tests"
BUILD = TESTS / ".build"
TIMEOUT = 2.0

# -D_GLIBCXX_DEBUG: vector の範囲外アクセスを検出 / -ftrapv: int のオーバーフローを検出
CXX = ["g++-15", "-std=c++17", "-O1", "-g", "-D_GLIBCXX_DEBUG", "-ftrapv"]

RED, GREEN, YELLOW, DIM, RESET = "\033[31m", "\033[32m", "\033[33m", "\033[2m", "\033[0m"


def compile_cpp(src: Path, name: str) -> Path:
    BUILD.mkdir(parents=True, exist_ok=True)
    exe = BUILD / name
    if exe.exists() and exe.stat().st_mtime > src.stat().st_mtime:
        return exe
    r = subprocess.run(CXX + [str(src), "-o", str(exe)], capture_output=True, text=True)
    if r.returncode != 0:
        print(f"{RED}コンパイルエラー: {src.relative_to(ROOT)}{RESET}\n{r.stderr}")
        sys.exit(1)
    return exe


def run(exe: Path, inp: str):
    """(stdout, stderr, 状態) を返す。状態は ok / crash(rc=..) / timeout"""
    try:
        r = subprocess.run([str(exe)], input=inp, capture_output=True, text=True, timeout=TIMEOUT)
    except subprocess.TimeoutExpired:
        return "", "", "timeout"
    return r.stdout, r.stderr, "ok" if r.returncode == 0 else f"crash(rc={r.returncode})"


def norm(s: str) -> str:
    """行末の空白と末尾の空行は無視して比較する"""
    return "\n".join(line.rstrip() for line in s.rstrip().splitlines())


def clip(s: str, n: int = 15) -> str:
    lines = s.rstrip("\n").splitlines()
    return "\n".join(lines[:n]) + (f"\n{DIM}... (残り {len(lines) - n} 行){RESET}" if len(lines) > n else "")


def show_diff(expected: str, got: str):
    e, g = norm(expected).splitlines(), norm(got).splitlines()
    for i in range(max(len(e), len(g))):
        el = e[i] if i < len(e) else "(なし)"
        gl = g[i] if i < len(g) else "(なし)"
        if el != gl:
            print(f"  {i + 1}行目\n    期待: {el!r}\n    出力: {gl!r}")
            return


# ---------- ランダム入力 ----------

def load_gen(name: str):
    path = TESTS / "gen" / f"{name}.py"
    if not path.exists():
        return None
    sys.path.insert(0, str(TESTS / "gen"))
    spec = importlib.util.spec_from_file_location(name, path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod.gen


def mutate(sample: str, r: random.Random) -> str:
    """生成器が無い問題用: サンプル中の整数を 0 / ±1 / 符号反転 / 近い乱数 に置き換える"""
    def repl(m):
        v = int(m.group())
        a = abs(v)
        return str(r.choice([v, v, 0, 1, -1, -v, v + 1, v - 1, r.randint(-2 * a - 5, 2 * a + 5)]))
    return re.sub(r"-?\d+", repl, sample)


# ---------- 各ステージ ----------

def stage_sample(exe, name) -> bool:
    fin, fout = ROOT / "answers/samples" / f"{name}.in", ROOT / "answers/samples" / f"{name}.out"
    if not fin.exists():
        print(f"{DIM}[sample] なし{RESET}")
        return True
    out, err, st = run(exe, fin.read_text())
    if st != "ok":
        print(f"{RED}[sample] {st}{RESET}\n{err}")
        return False
    if fout.exists() and norm(out) != norm(fout.read_text()):
        print(f"{RED}[sample] WA{RESET}")
        show_diff(fout.read_text(), out)
        return False
    print(f"{GREEN}[sample] OK{RESET}")
    return True


def stage_edge(exe, name) -> bool:
    files = sorted((TESTS / "edge" / name).glob("*.in"))
    if not files:
        print(f"{DIM}[edge] tests/edge/{name}/*.in なし{RESET}")
        return True
    ok = True
    for f in files:
        inp = f.read_text()
        out, err, st = run(exe, inp)
        exp = f.with_suffix(".out")
        if st != "ok":
            tag, ok = f"{RED}{st}{RESET}", False
        elif exp.exists():
            good = norm(out) == norm(exp.read_text())
            tag = f"{GREEN}OK{RESET}" if good else f"{RED}WA{RESET}"
            ok &= good
        else:
            tag = f"{YELLOW}出力を目視確認{RESET}"
        print(f"[edge] {f.name}: {tag}")
        print(f"{DIM}--- 入力 ---{RESET}\n{clip(inp)}\n{DIM}--- 出力 ---{RESET}\n{clip(out)}")
        if err:
            print(f"{RED}{clip(err)}{RESET}")
        if exp.exists() and st == "ok" and norm(out) != norm(exp.read_text()):
            show_diff(exp.read_text(), out)
    return ok


def stage_random(exe, name, n, seed, show) -> bool:
    gen = load_gen(name)
    sample = ROOT / "answers/samples" / f"{name}.in"
    if gen is None and not sample.exists():
        print(f"{DIM}[random] 生成器もサンプルも無いのでスキップ{RESET}")
        return True
    if gen is None:
        gen = lambda r: mutate(sample.read_text(), r)
        print(f"{DIM}[random] tests/gen/{name}.py が無いのでサンプルを変異させて使います（仕様外の入力も出ます）{RESET}")

    brute_src = TESTS / "brute" / f"{name}.cpp"
    brute = compile_cpp(brute_src, f"{name}_brute") if brute_src.exists() else None

    seed = seed if seed is not None else random.randrange(10**9)
    r = random.Random(seed)
    for i in range(1, n + 1):
        inp = gen(r)
        out, err, st = run(exe, inp)
        problem = None
        if st != "ok":
            problem = st
        elif brute:
            bout, _, bst = run(brute, inp)
            if bst == "ok" and norm(out) != norm(bout):
                problem = "WA（愚直解と不一致）"
        if show or problem:
            color = RED if problem else DIM
            print(f"{color}[random #{i}] {problem or 'ok'}{RESET}")
            print(f"{DIM}--- 入力 ---{RESET}\n{clip(inp)}\n{DIM}--- 出力 ---{RESET}\n{clip(out)}")
            if err:
                print(f"{RED}{clip(err)}{RESET}")
        if problem:
            if brute and problem.startswith("WA"):
                show_diff(bout, out)
            failed = TESTS / "failed" / f"{name}.in"
            failed.parent.mkdir(exist_ok=True)
            failed.write_text(inp)
            print(f"{YELLOW}入力を {failed.relative_to(ROOT)} に保存しました（seed={seed}）{RESET}")
            return False
    print(f"{GREEN}[random] {n}件 落ちずに完走{' + 愚直解と一致' if brute else ''}{RESET} {DIM}(seed={seed}){RESET}")
    return True


def stage_failed(exe, name) -> bool:
    f = TESTS / "failed" / f"{name}.in"
    if not f.exists():
        print(f"{DIM}[failed] 保存された失敗ケースなし{RESET}")
        return True
    inp = f.read_text()
    out, err, st = run(exe, inp)
    print(f"[failed] {st}\n{DIM}--- 入力 ---{RESET}\n{clip(inp)}\n{DIM}--- 出力 ---{RESET}\n{clip(out)}")
    if err:
        print(f"{RED}{clip(err)}{RESET}")
    return st == "ok"


def problem_index():
    """answers/ の1行目「// CPE01 Vito's Family (UVa 10041)」から {CPE番号: (タイトル, UVa番号)} を作る"""
    idx = {}
    for f in sorted((ROOT / "answers").glob("CPE*.cpp")):
        m = re.match(r"//\s*(CPE\d{2})\s*(.*?)\s*\(UVa\s*(\d+)\)", f.open().readline())
        if m:
            idx[m.group(1)] = (m.group(2), m.group(3))
    return idx


def resolve_problem(target: Path):
    """パス → ファイル内のコメント → ファイル名のUVa番号 → ファイル名とタイトルの一致 の順で CPExx を探す"""
    m = re.findall(r"CPE\d{2}", str(target))
    if m:
        return m[-1]
    if target.suffix == ".cpp" and target.exists():
        m = re.search(r"CPE\d{2}", target.read_text(errors="ignore"))
        if m:
            return m.group()
    idx = problem_index()
    stem = re.sub(r"[^a-z0-9]", "", target.stem.lower())
    for name, (_, uva) in idx.items():
        if re.match(rf"{uva}(?!\d)", stem):
            return name
    if len(stem) >= 4:
        for name, (title, _) in idx.items():
            if stem in re.sub(r"[^a-z0-9]", "", title.lower()):
                return name
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target", help="CPE02 や answers/CPE02.cpp など（パス中の CPExx を拾う）")
    ap.add_argument("--n", type=int, default=100, help="ランダムテストの件数")
    ap.add_argument("--seed", type=int)
    ap.add_argument("--show", action="store_true", help="ランダムの入出力を毎回表示")
    ap.add_argument("--only", choices=["sample", "edge", "random", "failed"])
    a = ap.parse_args()

    target = Path(a.target)
    name = resolve_problem(target)
    if not name:
        sys.exit(f"'{a.target}' がどの問題か分かりません。\n"
                 f"ファイルのどこかに // CPE24 のように問題番号を書くと認識します。")
    # .cpp を渡されたらそのファイル自体をテスト（notes/ の練習コードなど）、それ以外は answers/ の解答
    src = target.resolve() if target.suffix == ".cpp" else ROOT / "answers" / f"{name}.cpp"
    if not src.exists():
        sys.exit(f"{src} がありません")

    print(f"== {name}: {src.relative_to(ROOT)} ==")
    exe = compile_cpp(src, name if src.parent == ROOT / "answers" else f"{name}_{src.stem}")
    stages = {
        "sample": lambda: stage_sample(exe, name),
        "edge": lambda: stage_edge(exe, name),
        "random": lambda: stage_random(exe, name, a.n, a.seed, a.show),
        "failed": lambda: stage_failed(exe, name),
    }
    order = [a.only] if a.only else ["sample", "edge", "random"]
    results = [stages[s]() for s in order]
    sys.exit(0 if all(results) else 1)


if __name__ == "__main__":
    main()
