// CPE49-47 Mutant Flatworld Explorers (UVa 118)
// 考え方: ロボットの位置 (x, y) と向き（N, E, S, W を 0〜3 の番号）を持って命令を1文字ずつ実行する。
//         L は向き −1、R は向き +1（4 で割った余り）、F は向いている方向に1マス進む。
//         盤面の外に出るなら LOST。その直前の位置に「匂い」を残し、
//         以後のロボットはその位置から外に出る命令を無視する。
// 計算量: 1台 O(命令の長さ)
// 注意: 匂いは「落ちる直前にいたマス」に残る。匂いのあるマスでも、外に出ない F は普通に実行する。
//       LOST したらそのロボットの残りの命令は実行しない。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string DIR = "NESW";
    const int dx[4] = {0, 1, 0, -1};  // N, E, S, W
    const int dy[4] = {1, 0, -1, 0};

    int maxX, maxY;
    cin >> maxX >> maxY;

    bool scent[51][51] = {};

    int x, y;
    char d;
    string cmds;
    while (cin >> x >> y >> d >> cmds) {
        int dir = DIR.find(d);
        bool lost = false;

        for (char c : cmds) {
            if (c == 'L') {
                dir = (dir + 3) % 4;
            } else if (c == 'R') {
                dir = (dir + 1) % 4;
            } else if (c == 'F') {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx > maxX || ny < 0 || ny > maxY) {
                    if (scent[x][y]) continue;  // 前のロボットが落ちた場所 → 無視
                    scent[x][y] = true;
                    lost = true;
                    break;
                }
                x = nx;
                y = ny;
            }
        }

        cout << x << " " << y << " " << DIR[dir];
        if (lost) cout << " LOST";
        cout << "\n";
    }

    return 0;
}
