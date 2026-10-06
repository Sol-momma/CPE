// CPE26044 Expanding Fractions (UVa 275)
// 考え方: 筆算の割り算と同じ。余り r に 10 を掛けて d で割った商が次の1桁、余りが次の r。
//         同じ余りが2回出たらそこから先は繰り返しなので、その直前で止める。
//         余りが 0 になったら割り切れた（terminates）。
// 計算量: O(分母) / 行
// 注意: 余りが最初に出た位置を seen[r] に覚えておくと、繰り返しの長さ = 今の桁数 - seen[r]。
//       小数点を含めて 50文字ごとに改行する。各ケースの最後に空行が1つ入る。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    while (scanf("%d %d", &n, &d) == 2) {
        if (n == 0 && d == 0) break;

        vector<int> seen(d, -1);  // 余り r が最初に現れた桁の位置
        string digits;
        int r = n;
        int repeat = 0;           // 0 のままなら割り切れた
        while (true) {
            if (r == 0) break;    // 割り切れた
            if (seen[r] != -1) {  // 同じ余りが再登場 → ここから繰り返し
                repeat = (int)digits.size() - seen[r];
                break;
            }
            seen[r] = digits.size();
            r *= 10;
            digits += char('0' + r / d);
            r %= d;
        }

        string s = "." + digits;
        for (size_t i = 0; i < s.size(); i += 50) {
            printf("%s\n", s.substr(i, 50).c_str());
        }
        if (repeat == 0) {
            printf("This expansion terminates.\n");
        } else {
            printf("The last %d digits repeat forever.\n", repeat);
        }
        printf("\n");
    }
    return 0;
}
