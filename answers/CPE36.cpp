// CPE36 Largest Square (UVa 10908)
// 考え方: 中心 (r, c) から半径 k を 1, 2, 3, ... と広げ、辺 2k+1 の正方形が
//         「グリッドからはみ出さない」かつ「全部が中心と同じ文字」である間だけ広げ続ける。
//         最後に成功した半径 k に対して答えは 2k+1。
// 計算量: 1クエリあたり O(min(M, N)^3) 程度。M, N ≤ 100 なので十分。
// 注意: 中心がマスなので辺の長さは必ず奇数。各テストケースの最初に "M N Q" を出力する。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int m, n, q;
        cin >> m >> n >> q;
        vector<string> grid(m);
        for (int i = 0; i < m; i++) cin >> grid[i];

        cout << m << " " << n << " " << q << "\n";
        while (q--) {
            int r, c;
            cin >> r >> c;
            char center = grid[r][c];

            int k = 0;  // 今のところ OK な半径
            while (true) {
                int nk = k + 1;
                if (r - nk < 0 || r + nk >= m || c - nk < 0 || c + nk >= n) break;

                bool same = true;
                for (int i = r - nk; i <= r + nk && same; i++) {
                    for (int j = c - nk; j <= c + nk; j++) {
                        if (grid[i][j] != center) {
                            same = false;
                            break;
                        }
                    }
                }
                if (!same) break;
                k = nk;
            }
            cout << 2 * k + 1 << "\n";
        }
    }

    return 0;
}
