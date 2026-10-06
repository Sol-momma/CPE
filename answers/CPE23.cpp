// CPE23 B2-Sequence (UVa 11063)
// 考え方: 条件は3つ。(1) b1 ≥ 1、(2) 狭義単調増加（b1 < b2 < ...）、
//         (3) i ≤ j のすべてのペアの和 bi + bj がすべて異なる。
//         和は最大 20000 なので、bool 配列で「この和はもう出たか」を記録する。
// 計算量: O(N^2) / ケース
// 注意: 各ケースの出力の「後」に毎回空行を入れる（最後のケースにも付ける）。
//       i = j（同じ要素2回）の和も数える。入力は EOF まで。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tc = 0;
    while (cin >> n) {
        tc++;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        bool ok = (b[0] >= 1);
        for (int i = 1; i < n; i++) {
            if (b[i] <= b[i - 1]) ok = false;
        }

        vector<bool> used(20001, false);
        for (int i = 0; i < n && ok; i++) {
            for (int j = i; j < n; j++) {
                int s = b[i] + b[j];
                if (used[s]) {
                    ok = false;
                    break;
                }
                used[s] = true;
            }
        }

        cout << "Case #" << tc << ": " << (ok ? "It is a B2-Sequence." : "It is not a B2-Sequence.") << "\n\n";
    }

    return 0;
}
