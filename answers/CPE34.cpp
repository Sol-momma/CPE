// CPE34 2 the 9s (UVa 10922)
// 考え方: 最大1000桁なので文字列で読み、各桁の和 S を求める。S が 9 の倍数でなければ N も違う。
//         9 の倍数なら、「桁の和を取る」操作を1桁になるまで繰り返し、その回数が 9-degree。
// 計算量: O(桁数)
// 注意: 数が大きすぎて long long に入らないので必ず文字列で扱う。
//       "9" 自身の 9-degree は 1（1回目の和が 9 で終わる）。
#include <bits/stdc++.h>
using namespace std;

int digitSum(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s && s != "0") {
        int sum = 0;
        for (char ch : s) sum += ch - '0';

        if (sum % 9 != 0) {
            cout << s << " is not a multiple of 9.\n";
            continue;
        }

        int degree = 1;        // 1回目の和（sum）を取った
        while (sum >= 10) {    // まだ2桁以上なら、もう一度和を取る
            sum = digitSum(sum);
            degree++;
        }
        cout << s << " is a multiple of 9 and has 9-degree " << degree << ".\n";
    }

    return 0;
}
