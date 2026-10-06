// CPE29 Cheapest Base (UVa 11005)
// 考え方: 基数 2〜36 それぞれで数を書き直し（% base と / base で桁を取り出す）、桁の文字のコストを合計する。
//         最小コストを求めてから、最小と同じコストの基数をすべて小さい順に出力する。
// 計算量: 1クエリあたり O(35 × 桁数)
// 注意: 0 は "0" の1文字として扱う（ループが1回も回らないのでコスト0にしないこと）。
//       ケースの「間」に空行（最後のケースの後には付けない）。数は最大 2000000000 なので long long。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int cost[36];
        for (int i = 0; i < 36; i++) cin >> cost[i];

        if (tc > 1) cout << "\n";
        cout << "Case " << tc << ":\n";

        int q;
        cin >> q;
        while (q--) {
            long long num;
            cin >> num;

            int total[37];
            int best = INT_MAX;
            for (int base = 2; base <= 36; base++) {
                total[base] = 0;
                if (num == 0) {
                    total[base] = cost[0];
                } else {
                    long long x = num;
                    while (x > 0) {
                        total[base] += cost[x % base];
                        x /= base;
                    }
                }
                best = min(best, total[base]);
            }

            cout << "Cheapest base(s) for number " << num << ":";
            for (int base = 2; base <= 36; base++) {
                if (total[base] == best) cout << " " << base;
            }
            cout << "\n";
        }
    }

    return 0;
}
