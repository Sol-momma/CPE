// CPE26073 LC-Display (UVa 706)
// 考え方: 1桁は 7本の線（上・左上・右上・中・左下・右下・下）の組み合わせでできている。
//         数字ごとに「どの線を光らせるか」を表にしておく。
//         出力は 1行ずつ作る。全部で 2s+3 行あり、行ごとに
//           線の行（0行目・s+1行目・2s+2行目）→ s 個の '-' を出す
//           縦の行（それ以外の上半分・下半分）→ 左と右の '|' を出す
//         を数字の数だけ左から並べる。
// 計算量: O(桁数 × s × 行数)
// 注意: 1桁は幅 s+2 で、桁と桁の間に空白1つ。行末の空白も省略しない。
//       各数の出力のあとに空行を出す。入力は s = 0 で終了。
//       n は先頭の 0 を保つため文字列で読む。
#include <bits/stdc++.h>
using namespace std;

// 各数字で光らせる線: 上, 左上, 右上, 中, 左下, 右下, 下
const bool SEG[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},  // 0
    {0, 0, 1, 0, 0, 1, 0},  // 1
    {1, 0, 1, 1, 1, 0, 1},  // 2
    {1, 0, 1, 1, 0, 1, 1},  // 3
    {0, 1, 1, 1, 0, 1, 0},  // 4
    {1, 1, 0, 1, 0, 1, 1},  // 5
    {1, 1, 0, 1, 1, 1, 1},  // 6
    {1, 0, 1, 0, 0, 1, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1},  // 9
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    string n;
    while (cin >> s >> n) {
        if (s == 0) break;

        int rows = 2 * s + 3;
        for (int r = 0; r < rows; r++) {
            string line;
            for (size_t k = 0; k < n.size(); k++) {
                if (k > 0) line += ' ';  // 桁と桁の間
                const bool* seg = SEG[n[k] - '0'];

                if (r == 0 || r == s + 1 || r == 2 * s + 2) {
                    // 横線の行
                    int idx = (r == 0) ? 0 : (r == s + 1) ? 3 : 6;
                    line += ' ';
                    line += string(s, seg[idx] ? '-' : ' ');
                    line += ' ';
                } else {
                    // 縦線の行: 上半分は左上・右上、下半分は左下・右下
                    bool upper = (r < s + 1);
                    bool left = upper ? seg[1] : seg[4];
                    bool right = upper ? seg[2] : seg[5];
                    line += left ? '|' : ' ';
                    line += string(s, ' ');
                    line += right ? '|' : ' ';
                }
            }
            cout << line << "\n";
        }
        cout << "\n";
    }
    return 0;
}
