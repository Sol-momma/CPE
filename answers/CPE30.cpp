// CPE30 Hartals (UVa 10050)
// 考え方: 1日目〜N日目を1日ずつ調べ、「どれかの政党の h で割り切れる」かつ「金曜・土曜でない」日を数える。
//         1日目が日曜なので、d % 7 == 6 が金曜、d % 7 == 0 が土曜。
// 計算量: O(N × P) = 最大 3650 × 100
// 注意: 同じ日に複数の政党がハルタルをしても1日として数える（見つけたら break）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> h(p);
        for (int i = 0; i < p; i++) cin >> h[i];

        int lost = 0;
        for (int day = 1; day <= n; day++) {
            if (day % 7 == 6 || day % 7 == 0) continue;  // 金曜・土曜は休日
            for (int i = 0; i < p; i++) {
                if (day % h[i] == 0) {
                    lost++;
                    break;
                }
            }
        }
        cout << lost << "\n";
    }

    return 0;
}
