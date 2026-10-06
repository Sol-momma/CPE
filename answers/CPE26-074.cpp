// CPE26-074 Not That Kind of Graph (UVa 10800)
// 考え方: 株価の高さ h を 0 から始めて、1文字ずつ処理する。
//           R: 今の高さの行に '/' を置き、h を 1 上げる。
//           F: h を 1 下げてから、その高さの行に '\' を置く。
//           C: 今の高さの行に '_' を置く（h は変わらない）。
//         高さをもとに 2次元の表（行 × 列）へ書き込み、最後に上の行から出力する。
// 計算量: O(文字数^2)（表の大きさ分）
// 注意: 高さは負にもなるので、最初に 60 を足した位置を 0 とみなして配列に書き込む。
//       使われていない行は出力しない。各行は「| 」のあとに文字を並べ、行末の空白は消す。
//       x軸は '+' のあとに '-' を (文字数+2) 個。各ケースの後ろに空行を出す。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        string s;
        cin >> s;
        int len = s.size();

        const int OFFSET = 60;  // 高さ 0 を配列の 60 行目に置く（負の高さ対策）
        vector<string> grid(2 * OFFSET + 2, string(len, ' '));

        int h = 0;
        int lo = INT_MAX, hi = INT_MIN;  // 使った行の範囲
        for (int i = 0; i < len; i++) {
            int row;
            char ch;
            if (s[i] == 'R') {
                row = h;
                ch = '/';
                h++;
            } else if (s[i] == 'F') {
                h--;
                row = h;
                ch = '\\';
            } else {
                row = h;
                ch = '_';
            }
            grid[row + OFFSET][i] = ch;
            lo = min(lo, row);
            hi = max(hi, row);
        }

        cout << "Case #" << tc << ":\n";
        for (int row = hi; row >= lo; row--) {
            string line = grid[row + OFFSET];
            while (!line.empty() && line.back() == ' ') line.pop_back();  // 行末の空白を消す
            cout << "| " << line << "\n";
        }
        cout << "+" << string(len + 2, '-') << "\n\n";
    }
    return 0;
}
