// CPE26-072 Where's Waldorf? (UVa 10010)
// 考え方: 単語ごとに、グリッドの全マスを開始位置、8方向を向きとして試し、
//         単語が最後まで一致するか調べる。
//         開始位置を「上の行から、同じ行なら左から」の順に調べれば、最初に見つかったものが答え。
//         大文字・小文字は区別しないので、先にすべて小文字にそろえておく。
// 計算量: O(k × m × n × 8 × 単語の長さ)
// 注意: グリッドの外にはみ出したら不一致。出力は 1 始まりの行・列。
//       テストケースの「間」に空行を入れる（最後のあとには入れない）。
//       入力の空行は cin >> が読み飛ばしてくれる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int m, n;
        cin >> m >> n;
        vector<string> g(m);
        for (int i = 0; i < m; i++) {
            cin >> g[i];
            for (char& c : g[i]) c = tolower(c);
        }

        int k;
        cin >> k;
        if (tc > 0) cout << "\n";
        while (k--) {
            string w;
            cin >> w;
            for (char& c : w) c = tolower(c);
            int len = w.size();

            bool found = false;
            for (int i = 0; i < m && !found; i++) {
                for (int j = 0; j < n && !found; j++) {
                    for (int d = 0; d < 8 && !found; d++) {
                        int p = 0;
                        while (p < len) {
                            int x = i + dx[d] * p, y = j + dy[d] * p;
                            if (x < 0 || x >= m || y < 0 || y >= n) break;
                            if (g[x][y] != w[p]) break;
                            p++;
                        }
                        if (p == len) {
                            cout << i + 1 << " " << j + 1 << "\n";
                            found = true;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
