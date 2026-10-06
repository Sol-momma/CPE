// CPE26083 Credit Check (UVa 11743)
// 考え方: カード番号の 16桁を、右（最後の桁）から数えて 2番目・4番目・…の桁を 2倍にする。
//         2倍して 10 以上になったら「各桁の和」にする（= 10 以上なら 9 を引くのと同じ）。
//         全部足して 10 で割り切れれば Valid。
// 計算量: O(16) / 1枚
// 注意: 入力は 4桁ずつ空白で区切られている。4つの文字列を読んでつなげて 1本の文字列にする。
//       2倍するのは「最後から2番目」の桁（0 始まりで添字 14, 12, ..., 0 = 偶数番目）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string num, part;
        for (int i = 0; i < 4; i++) {
            cin >> part;
            num += part;
        }

        int total = 0;
        int len = num.size();
        for (int i = 0; i < len; i++) {
            int d = num[i] - '0';
            // 右から数えた位置（最後の桁が 0）。奇数番目を 2倍する。
            int fromRight = len - 1 - i;
            if (fromRight % 2 == 1) {
                d *= 2;
                if (d >= 10) d = d / 10 + d % 10;  // 桁の和
            }
            total += d;
        }

        cout << (total % 10 == 0 ? "Valid" : "Invalid") << "\n";
    }
    return 0;
}
