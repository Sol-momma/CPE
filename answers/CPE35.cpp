// CPE35 GCD (UVa 11417)
// 考え方: 問題文のコードそのまま。i < j のすべての組について gcd(i, j) を足す。
// 計算量: O(N^2 log N)。N < 501 なので1ケース約12万回 × 100ケースで十分間に合う。
// 注意: 0 が来たら終了（出力しない）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        long long g = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                g += __gcd(i, j);
            }
        }
        cout << g << "\n";
    }

    return 0;
}
