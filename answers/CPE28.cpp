// CPE28 Parity (UVa 10931)
// 考え方: % 2 と / 2 を繰り返すと2進数の桁が右から取れる。取れた桁を文字列の前に足していき、1 の個数も数える。
// 計算量: O(log I)
// 注意: 出力は "The parity of B is P (mod 2)."。P は 1 の個数そのもの（2 で割った余りではない）。
//       I は最大 2147483647 なので int でぎりぎり入るが、念のため long long。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n && n != 0) {
        string binary = "";
        int ones = 0;
        while (n > 0) {
            int bit = n % 2;
            binary = char('0' + bit) + binary;
            ones += bit;
            n /= 2;
        }
        cout << "The parity of " << binary << " is " << ones << " (mod 2).\n";
    }

    return 0;
}
