// CPE26104 Spiral Tap (UVa 10920)
// 考え方: 1番は中心。そこから 上1・左1・下2・右2・上3・左3・… と、
//         歩く長さが2回ごとに1ずつ増える渦巻きをたどる。
//         P-1 歩だけ進めば P 番の位置。1歩ずつではなく「辺ごと」にまとめて進める。
// 計算量: O(SZ)/行（辺の数は SZ 本ほど）
// 注意: 出力は "Line = 行, column = 列." で、行(line)が下から数えた y、列(column)が x。
//       P は最大 10^10 なので long long。SZ = P = 0 で終了。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sz, p;
    while (cin >> sz >> p && !(sz == 0 && p == 0)) {
        long long line = (sz + 1) / 2;  // 中心（1番）の位置
        long long col = (sz + 1) / 2;
        long long left = p - 1;         // あと何歩進むか

        // 向き: 0=上, 1=左, 2=下, 3=右
        const int dline[4] = {1, 0, -1, 0};
        const int dcol[4] = {0, -1, 0, 1};

        int dir = 0;
        long long len = 1;  // 今の辺の長さ
        int doneInLen = 0;  // 同じ長さの辺を何本歩いたか（2本で長さ+1）
        while (left > 0) {
            long long step = min(len, left);
            line += dline[dir] * step;
            col += dcol[dir] * step;
            left -= step;
            dir = (dir + 1) % 4;
            doneInLen++;
            if (doneInLen == 2) {
                doneInLen = 0;
                len++;
            }
        }
        cout << "Line = " << line << ", column = " << col << ".\n";
    }
    return 0;
}
