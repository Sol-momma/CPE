// CPE02 Hashmat the Brave Warrior (UVa 10055)
// 考え方: 2つの数の差の絶対値を出力するだけ。
// 計算量: O(1) / 行
// 注意: 入力は 2^32 まであり int に入らないので long long を使う。
//       "vice versa"（逆の順もある）ので、引き算の結果は abs を取る。
//       入力は EOF まで続く。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    while (cin >> a >> b) {
        cout << llabs(a - b) << "\n";
    }
    return 0;
}
