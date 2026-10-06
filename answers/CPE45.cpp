// CPE45 Die Game (UVa 10409)
// 考え方: サイコロの6面（上・北・西・下・南・東）を変数で持ち、命令ごとに4面を入れ替える。
//         最初は 上=1, 北=2, 西=3。向かい合う面の和は 7 なので 下=6, 南=5, 東=4。
//         例: "north" は北へ転がす → 上が北へ、北が下へ、下が南へ、南が上へ移る。
// 計算量: 1ゲーム O(命令数)
// 注意: 0 が来たら入力終了。転がす向きと面の移り方を取り違えやすいので、サンプルで確認する。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        int top = 1, north = 2, west = 3, bottom = 6, south = 5, east = 4;

        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;
            int t = top;
            if (cmd == "north") {
                top = south; south = bottom; bottom = north; north = t;
            } else if (cmd == "south") {
                top = north; north = bottom; bottom = south; south = t;
            } else if (cmd == "east") {
                top = west; west = bottom; bottom = east; east = t;
            } else if (cmd == "west") {
                top = east; east = bottom; bottom = west; west = t;
            }
        }

        cout << top << "\n";
    }

    return 0;
}
