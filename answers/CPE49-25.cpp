// CPE49-25 An Easy Problem! (UVa 10093)
// 考え方: N 進数 R が (N-1) で割り切れる ⇔ R の各桁の和が (N-1) で割り切れる（10進数の「9の倍数判定」と同じ理屈）。
//         使われている最大の桁 +1（最低 2）から 62 まで N を小さい順に試し、桁の和 % (N-1) == 0 なら答え。
// 計算量: O(桁数 + 62)
// 注意: 入力に '+' / '-' 符号が付くことがあるので、0-9 A-Z a-z 以外の文字は無視する。
//       どの N でもダメなら "such number is impossible!"。
#include <bits/stdc++.h>
using namespace std;

int digitValue(char ch) {
    if ('0' <= ch && ch <= '9') return ch - '0';
    if ('A' <= ch && ch <= 'Z') return ch - 'A' + 10;
    if ('a' <= ch && ch <= 'z') return ch - 'a' + 36;
    return -1;  // 符号などの記号
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        long long sum = 0;
        int maxDigit = 0;
        for (char ch : s) {
            int d = digitValue(ch);
            if (d < 0) continue;
            sum += d;
            maxDigit = max(maxDigit, d);
        }

        int answer = -1;
        for (int n = max(maxDigit + 1, 2); n <= 62; n++) {
            if (sum % (n - 1) == 0) {
                answer = n;
                break;
            }
        }

        if (answer == -1) cout << "such number is impossible!\n";
        else cout << answer << "\n";
    }

    return 0;
}
