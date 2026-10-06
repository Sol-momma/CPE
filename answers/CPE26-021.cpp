// CPE26-021 One-Two-Three (UVa 12289)
// 考え方: 長さが5なら three（長さが違うのは one/two と three だけ）。
//         長さ3なら "one" と1文字ずつ比べ、2文字以上合っていれば one、そうでなければ two。
//         間違いは高々1文字なので、本物と比べると必ず 2文字以上は合っている。
// 計算量: O(単語数)
// 注意: 長さは必ず正しいと保証されている。one と two は同じ長さ3なので文字の一致数で見分ける。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() == 5) {
            cout << 3 << "\n";
        } else {
            int match = 0;  // "one" と一致している文字数
            string one = "one";
            for (int i = 0; i < 3; i++) {
                if (s[i] == one[i]) match++;
            }
            cout << (match >= 2 ? 1 : 2) << "\n";
        }
    }
    return 0;
}
