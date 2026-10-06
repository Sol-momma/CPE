// CPE31 All You Need Is Love! (UVa 10193)
// 考え方: 「S から L を何度も引いて L にできる」= S が L の倍数。
//         S1 と S2 の両方が L の倍数になる L（2以上）が存在する ⇔ gcd(S1, S2) > 1。
//         2進数の文字列を整数に直して gcd を取るだけ。
// 計算量: O(文字列長 + log)
// 注意: 文字列は最大30文字なので long long に入る。出力は "Pair #p: ..."。
#include <bits/stdc++.h>
using namespace std;

long long binaryToNumber(const string& s) {
    long long value = 0;
    for (char ch : s) value = value * 2 + (ch - '0');
    return value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int p = 1; p <= n; p++) {
        string s1, s2;
        cin >> s1 >> s2;
        long long g = __gcd(binaryToNumber(s1), binaryToNumber(s2));

        cout << "Pair #" << p << ": ";
        if (g > 1) cout << "All you need is love!\n";
        else cout << "Love is not all you need!\n";
    }

    return 0;
}
