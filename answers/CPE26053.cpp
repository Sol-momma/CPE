// CPE26053 Product of digits (UVa 993)
// 考え方: N を 9, 8, 7, ..., 2 の順に割れるだけ割り、使った桁を記録する。
//         大きい桁から割ると桁数が最小になる。最後に昇順に並べると最小の数になる。
//         最後に 1 以外が残ったら（7 より大きい素数を含む）答えは -1。
// 計算量: O(log N) / データ
// 注意: N = 0 は答え 10（桁の積が 0 になる最小の自然数）。N = 1 は答え 1。
//       答えは最大 10 桁近くになりうるので、数ではなく文字列として出力する。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n == 0) {
            cout << 10 << "\n";
            continue;
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        string digits;
        for (int d = 9; d >= 2; d--) {
            while (n % d == 0) {
                digits += char('0' + d);
                n /= d;
            }
        }

        if (n != 1) {
            cout << -1 << "\n";
        } else {
            sort(digits.begin(), digits.end());  // 小さい桁を上位に置く
            cout << digits << "\n";
        }
    }
    return 0;
}
