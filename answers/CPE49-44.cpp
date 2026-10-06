// CPE49-44 Minesweeper (UVa 10189)
// 考え方: '.' のマスごとに、周囲8マスにある '*' を数えて数字に置き換える。
//         周囲8マスは dx, dy をそれぞれ −1, 0, +1 で回して調べる（自分自身は除く）。
// 計算量: 1フィールド O(n × m × 8)
// 注意: 盤面の外を見ないように範囲チェックする。
//       出力は "Field #1:" の形式で、フィールドの「間」に空行（最後には付けない）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int field = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];

        field++;
        if (field > 1) cout << "\n";
        cout << "Field #" << field << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    cout << '*';
                    continue;
                }
                int mines = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int x = i + dx, y = j + dy;
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (g[x][y] == '*') mines++;
                    }
                }
                cout << mines;
            }
            cout << "\n";
        }
    }

    return 0;
}
