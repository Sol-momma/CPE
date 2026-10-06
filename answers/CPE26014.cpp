// CPE26014 Polynomial Showdown (UVa 392)
// 考え方: 係数を x^8 から x^0 の順に見て、0 でない項だけを文字列にしてつなげる。
//         最初の項は符号を「-」だけ、2つ目以降は " + " か " - " を前に付けて、係数は絶対値で書く。
// 計算量: O(1) / 行（係数は9個）
// 注意: 係数の絶対値が 1 のときは、x の項では「1」を省く（x^3 や -x）。定数項だけは 1 を書く。
//       次数1は x^1 ではなく x、次数0は x を付けない。全部 0 のときは「0」と出力する。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int c[9];  // c[0] が x^8 の係数、c[8] が定数項
    while (cin >> c[0]) {
        for (int i = 1; i < 9; i++) cin >> c[i];

        string out = "";
        for (int i = 0; i < 9; i++) {
            if (c[i] == 0) continue;
            int deg = 8 - i;
            int a = abs(c[i]);

            if (out.empty()) {
                if (c[i] < 0) out += "-";
            } else {
                out += (c[i] < 0) ? " - " : " + ";
            }

            if (deg == 0 || a != 1) out += to_string(a);  // 定数項は 1 でも書く
            if (deg >= 1) out += "x";
            if (deg >= 2) out += "^" + to_string(deg);
        }

        if (out.empty()) out = "0";
        cout << out << "\n";
    }
    return 0;
}
