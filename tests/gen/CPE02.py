# CPE02 Hashmat: 2つの数 (0 〜 2^32) の差の絶対値
# 仕様外の負の値も混ぜて、long long / llabs が効いているか確認する
from _lib import edgy


def gen(r):
    lines = []
    for _ in range(r.randint(1, 10)):
        a = edgy(r, -(2**32), 2**32)
        b = edgy(r, -(2**32), 2**32)
        lines.append(f"{a} {b}")
    return "\n".join(lines) + "\n"
