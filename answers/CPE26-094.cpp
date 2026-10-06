// CPE26-094 Alternate Task (UVa 11728)
// 考え方: S ≤ 1000 なので、n = 1〜1000 すべての約数の和を先に計算しておき、
//         約数の和が S になる n のうち最大のものを答える。
// 計算量: 前計算 O(1000^2)、各ケース O(1000)
// 注意: n > 1 なら約数の和は n+1 以上なので、答えは S 以下。調べる範囲は 1000 で足りる。
//       該当なしは -1。出力は "Case 番号: 答え"。S = 0 で終了。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1000;
    int sigma[MAXN + 1] = {0};  // sigma[n] = n の約数の和
    for (int n = 1; n <= MAXN; n++) {
        for (int d = 1; d <= n; d++) {
            if (n % d == 0) sigma[n] += d;
        }
    }

    int s, caseNo = 0;
    while (cin >> s && s != 0) {
        int ans = -1;
        for (int n = 1; n <= MAXN; n++) {
            if (sigma[n] == s) ans = n;  // 小さい順に見るので最後に残るのが最大
        }
        caseNo++;
        cout << "Case " << caseNo << ": " << ans << "\n";
    }
    return 0;
}
