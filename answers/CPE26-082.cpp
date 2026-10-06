// CPE26-082 Die Game (UVa 10409)
// 考え方: サイコロの 6面（上・下・北・南・西・東）の数字を変数で持ち、
//         転がすたびに 4つの面の数字を順番に入れ替える。
//         最初は 上=1, 北=2, 西=3。反対側の面との和は 7 なので 下=6, 南=5, 東=4。
//           north: 上→北→下→南→上 の向きに数字が移る（新しい上 = 前の南）
//           south: north の逆
//           east : 上→東→下→西→上（新しい上 = 前の西）
//           west : east の逆
// 計算量: O(命令数)
// 注意: 西と東は north/south では動かない。入れ替えは「上書きの前に古い値を退避」して順番を守る。
//       0 が来たら入力終了。コマンドは文字列で読む。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        int top = 1, bottom = 6, north = 2, south = 5, west = 3, east = 4;

        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;
            int oldTop = top, oldBottom = bottom;
            int oldNorth = north, oldSouth = south;
            int oldWest = west, oldEast = east;

            if (cmd == "north") {
                top = oldSouth;
                north = oldTop;
                bottom = oldNorth;
                south = oldBottom;
            } else if (cmd == "south") {
                top = oldNorth;
                south = oldTop;
                bottom = oldSouth;
                north = oldBottom;
            } else if (cmd == "east") {
                top = oldWest;
                east = oldTop;
                bottom = oldEast;
                west = oldBottom;
            } else if (cmd == "west") {
                top = oldEast;
                west = oldTop;
                bottom = oldWest;
                east = oldBottom;
            }
        }
        cout << top << "\n";
    }
    return 0;
}
