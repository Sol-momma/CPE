// CPE26144 Crazy King (UVa 11352)
// 考え方: 先に「王が入れないマス」に印を付ける。馬 Z のいるマスと、Z から馬の動き（8方向）で
//         届くマスが入れない。そのうえで A から B まで、王の動き（8方向）で BFS して最短手数を求める。
// 計算量: O(M × N) / ケース
// 注意: A と B のマスは、馬に狙われていても入ってよい（問題文の例外）。
//       行列の大きさは「M 行 N 列」の順で与えられる。
//       行きつけないときは "King Peter, you can't go now!"。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int knightDr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int knightDc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<string> g(M);
        for (int i = 0; i < M; i++) cin >> g[i];

        int sr = 0, sc = 0, er = 0, ec = 0;
        vector<vector<bool>> blocked(M, vector<bool>(N, false));
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (g[r][c] == 'A') { sr = r; sc = c; }
                if (g[r][c] == 'B') { er = r; ec = c; }
                if (g[r][c] == 'Z') {
                    blocked[r][c] = true;
                    for (int k = 0; k < 8; k++) {
                        int nr = r + knightDr[k];
                        int nc = c + knightDc[k];
                        if (nr >= 0 && nr < M && nc >= 0 && nc < N) blocked[nr][nc] = true;
                    }
                }
            }
        }
        blocked[sr][sc] = false;  // A と B は例外
        blocked[er][ec] = false;

        vector<vector<int>> dist(M, vector<int>(N, -1));
        queue<pair<int, int>> q;
        dist[sr][sc] = 0;
        q.push({sr, sc});
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = cur.first + dr;
                    int nc = cur.second + dc;
                    if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
                    if (blocked[nr][nc] || dist[nr][nc] != -1) continue;
                    dist[nr][nc] = dist[cur.first][cur.second] + 1;
                    q.push({nr, nc});
                }
            }
        }

        if (dist[er][ec] == -1) {
            cout << "King Peter, you can't go now!\n";
        } else {
            cout << "Minimal possible length of a trip is " << dist[er][ec] << "\n";
        }
    }
    return 0;
}
