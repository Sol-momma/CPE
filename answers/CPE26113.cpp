// CPE26113 The Hamming Distance Problem (UVa 729)
// 考え方: 長さ N のビット列を 0〜2^N-1 の整数として全部試し、1 がちょうど H 個のものだけ出力する。
//         整数の小さい順 = 文字列の辞書順なので、並べ替えは不要。
// 計算量: O(2^N * N)（N ≤ 16 なので十分）
// 注意: データセットの間に空行を入れる（最後の後ろには入れない）。
//       入力にも空行があるが、cin >> で読めば空白・空行は自動で飛ばされる。
//       出力は上位ビット（左端）から順に N 桁書く。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n, h;
        cin >> n >> h;

        if (tc > 0) cout << "\n";  // データセットの間の空行

        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != h) continue;
            string s;
            for (int b = n - 1; b >= 0; b--) {
                s += ((mask >> b) & 1) ? '1' : '0';
            }
            cout << s << "\n";
        }
    }
    return 0;
}
