// CPE26071 Minesweeper (UVa 10189)
// 考え方: 各マスについて、まわり8マスのうち '*' の数を数える。
//         '*' のマスはそのまま出し、'.' のマスは数えた個数に置き換える。
// 計算量: O(n × m × 8) / 盤面
// 注意: 盤面と盤面の「間」に空行を入れる（最後の盤面のあとには入れない）。
//       盤面の外にはみ出すマスは数えない（範囲チェックが必要）。
//       n = m = 0 で入力終了。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int caseNo = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];

        caseNo++;
        if (caseNo > 1) cout << "\n";  // 盤面の間に空行
        cout << "Field #" << caseNo << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    cout << '*';
                    continue;
                }
                int cnt = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        if (g[ni][nj] == '*') cnt++;
                    }
                }
                cout << cnt;
            }
            cout << "\n";
        }
    }
    return 0;
}
