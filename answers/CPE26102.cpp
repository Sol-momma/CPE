// CPE26102 Joana and the Odd Numbers (UVa 913)
// 考え方: k 行目には 2k-1 個ある。1行目〜k行目で奇数は全部で k^2 個なので、
//         k 行目の最後の数は「k^2 番目の奇数」= 2k^2-1。
//         最後の3つは 2k^2-1, 2k^2-3, 2k^2-5 なので、合計は 6k^2-9。
// 計算量: O(1)/行
// 注意: N は奇数で N = 2k-1 から k = (N+1)/2。N は 10^9 近くまでなので k^2 は int を超える。
//       long long を使う（答えは 2^63 未満と保証されている）。入力は EOF まで。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n) {
        long long k = (n + 1) / 2;  // k 行目
        cout << 6 * k * k - 9 << "\n";
    }
    return 0;
}
