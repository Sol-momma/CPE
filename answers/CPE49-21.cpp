// CPE49-21 Symmetric Matrix (UVa 11349)
// 考え方: 中心に対して点対称か調べる。M[i][j] と M[n-1-i][n-1-j] がすべて等しければ対称。
//         さらに、負の要素が1つでもあれば Non-symmetric（問題文の定義）。
// 計算量: O(n^2) / ケース
// 注意: 入力の2行目は「N = 3」という形式なので、"N" と "=" を文字列として読み飛ばす。
//       要素は ±2^32 まであるので long long。出力の末尾に「.」が付く。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string nStr, eqStr;
        int n;
        cin >> nStr >> eqStr >> n;  // "N" "=" 3

        vector<vector<long long>> m(n, vector<long long>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];

        bool symmetric = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][j] < 0 || m[i][j] != m[n - 1 - i][n - 1 - j]) {
                    symmetric = false;
                }
            }
        }

        cout << "Test #" << tc << ": " << (symmetric ? "Symmetric." : "Non-symmetric.") << "\n";
    }

    return 0;
}
