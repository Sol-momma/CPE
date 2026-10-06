// CPE26-081 Reverse and Add (UVa 10018)
// 考え方: 「回文でない間、今の数に『桁を逆にした数』を足す」を問題文どおりくり返し、
//         足した回数と最終的な回文を出力する。
//         桁の反転は % 10 で1桁ずつ取り出して作る。
// 計算量: O(反復回数 × 桁数)（反復は 1000 回未満）
// 注意: 結果の回文は 4,294,967,295 以下だが、途中の和も含めて int には入らない。long long を使う。
//       最初から回文の数は 0 回で、その数自身を出力する。
#include <bits/stdc++.h>
using namespace std;

long long reverseNum(long long x) {
    long long r = 0;
    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        long long p;
        cin >> p;

        int steps = 0;
        while (reverseNum(p) != p) {  // 反転しても同じ = 回文
            p += reverseNum(p);
            steps++;
        }
        cout << steps << " " << p << "\n";
    }
    return 0;
}
