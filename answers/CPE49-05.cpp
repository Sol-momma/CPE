// CPE49-05 You can say 11 (UVa 10929)
// 考え方: 最大1000桁なので数値型に入らない。文字列で読む。
//         11 の倍数判定は「奇数桁目の和 − 偶数桁目の和」が 11 の倍数かどうか。
// 計算量: O(桁数) / 行
// 注意: 終わりは "0" の1行だけ。出力は入力の文字列をそのまま使う。
// 別解: 先頭から r = (r*10 + 桁) % 11 と余りを更新していく方法でも判定できる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s == "0") break;

        int diff = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int d = s[i] - '0';
            if (i % 2 == 0) diff += d;
            else diff -= d;
        }

        if (diff % 11 == 0) cout << s << " is a multiple of 11.\n";
        else cout << s << " is not a multiple of 11.\n";
    }
    return 0;
}
