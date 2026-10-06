"""生成器で使う共通ヘルパー"""


def edgy(r, lo, hi):
    """lo〜hi の整数。3割くらいの確率で境界値（lo, hi, 0, ±1 など）を返す"""
    if r.random() < 0.3:
        return r.choice([v for v in (lo, hi, lo + 1, hi - 1, 0, 1, -1) if lo <= v <= hi])
    return r.randint(lo, hi)
