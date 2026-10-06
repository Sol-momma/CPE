// CPE49-13 TeX Quotes (UVa 272)
// 考え方: 1文字ずつ読み、" が来たら交互に `` と '' に置き換える。
//         「次の " は開きか閉じか」を bool で覚えておき、使うたびに反転する。
//         " は行をまたいでペアになるので、フラグはファイル全体で1つ。
// 計算量: O(文字数)
// 注意: 改行や空白もそのまま出力する必要があるので cin >> ではなく get() で1文字ずつ読む。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool open = true;  // 次の " が開き引用符なら true
    char c;
    while (cin.get(c)) {
        if (c == '"') {
            cout << (open ? "``" : "''");
            open = !open;
        } else {
            cout << c;
        }
    }

    return 0;
}
