// CPE49-09 Decode the Mad man (UVa 10222)
// 考え方: キーボードの並びを1本の文字列にしておき、入力の各文字について
//         その文字の「2つ左」の文字に置き換える。
// 計算量: O(文字数 × キーボード文字数)
// 注意: 大文字は小文字にしてから探す（出力は小文字）。
//       空白などキーボード文字列にない文字はそのまま出力する。
//       '\\' は C++ の文字列ではバックスラッシュ1文字を表す。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string kb = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    string line;
    while (getline(cin, line)) {
        for (char c : line) {
            char low = tolower(c);
            size_t pos = kb.find(low);
            if (pos != string::npos && pos >= 2) cout << kb[pos - 2];
            else cout << c;
        }
        cout << "\n";
    }
    return 0;
}
