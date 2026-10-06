// CPE26011 TeX Quotes (UVa 272)
// 考え方: 入力を1文字ずつ読んで、そのまま出力する。ただし " だけは `` と '' を交互に出す。
//         今が「開く側」か「閉じる側」かを bool 1つで覚えておけばよい。
// 計算量: O(文字数)
// 注意: 改行や空白もそのまま出す必要があるので、getline ではなく cin.get で1文字ずつ読む。
//       " は1つずつ数える（行をまたいでも続く）。行ごとにリセットしないこと。
#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    bool open = true;  // true なら次の " は開く側 ``
    while (cin.get(c)) {
        if (c == '"') {
            if (open) {
                cout << "``";
            } else {
                cout << "''";
            }
            open = !open;
        } else {
            cout << c;
        }
    }
    return 0;
}
