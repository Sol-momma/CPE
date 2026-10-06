// CPE26-022 Decoding (UVa 11541)
// 考え方: 「英字 + 数字」の組を前から順に読む。英字を覚え、続く数字をつなげて回数にし、その回数だけ出力する。
// 計算量: O(入力の長さ + 出力の長さ)
// 注意: 回数は2桁以上もある（A12）ので、数字は n = n*10 + 桁 で1桁ずつ組み立てる。
//       出力は "Case 1: ..." の形式。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string s;
        cin >> s;
        string result = "";
        int i = 0;
        while (i < (int)s.size()) {
            char letter = s[i];
            i++;
            int n = 0;
            while (i < (int)s.size() && isdigit((unsigned char)s[i])) {
                n = n * 10 + (s[i] - '0');
                i++;
            }
            result += string(n, letter);  // letter を n 個並べる
        }
        cout << "Case " << tc << ": " << result << "\n";
    }
    return 0;
}
