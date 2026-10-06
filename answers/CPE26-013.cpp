// CPE26-013 Molar mass (UVa 1586)
// 考え方: 式を左から読み、英大文字が来たら元素、その後ろの数字が個数（無ければ1個）。
//         元素ごとの原子量 × 個数を全部足す。
// 計算量: O(式の長さ) / ケース
// 注意: 個数は 2〜99 なので2桁もある（C12 など）。数字は1文字ずつ読んで n = n*10 + 桁 で組み立てる。
//       出力は小数第3位まで（printf("%.3f")）。
#include <bits/stdc++.h>
using namespace std;

double weightOf(char c) {
    if (c == 'C') return 12.01;
    if (c == 'H') return 1.008;
    if (c == 'O') return 16.00;
    return 14.01;  // 'N'
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        double total = 0;
        int i = 0;
        while (i < (int)s.size()) {
            char elem = s[i];
            i++;
            int n = 0;
            while (i < (int)s.size() && isdigit((unsigned char)s[i])) {
                n = n * 10 + (s[i] - '0');
                i++;
            }
            if (n == 0) n = 1;  // 数字が省略されていたら1個
            total += weightOf(elem) * n;
        }
        printf("%.3f\n", total);
    }
    return 0;
}
