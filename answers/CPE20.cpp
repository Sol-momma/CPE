// CPE20 Beat the Spread! (UVa 10812)
// 考え方: 2つの得点を x ≥ y とすると x + y = s, x - y = d。
//         連立方程式を解くと x = (s + d) / 2, y = (s - d) / 2。
//         y が負になる（s < d）か、(s + d) が奇数で割り切れないなら impossible。
// 計算量: O(1) / ケース
// 注意: 大きい方を先に出力する。得点は 0 以上の整数でなければならない。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        long long s, d;
        cin >> s >> d;
        if (s < d || (s + d) % 2 != 0) {
            cout << "impossible\n";
        } else {
            cout << (s + d) / 2 << " " << (s - d) / 2 << "\n";
        }
    }

    return 0;
}
