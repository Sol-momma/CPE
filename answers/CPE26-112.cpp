// CPE26-112 How do you add? (UVa 10943)
// 考え方: ways[k][n] = 「k個の非負整数を足して n になる場合の数」として表を作る（DP）。
//         k個目の数を i (0〜n) と決めると、残りの k-1 個で n-i を作ればよい。
//         ways[k][n] = ways[k-1][0] + ways[k-1][1] + ... + ways[k-1][n]
// 計算量: 表づくり O(100 * 100 * 100)、各質問は O(1)
// 注意: 問題文の "less than N" は実際には 0 と N も使える（例: 0+20 と 20+0 を数える）。
//       答えは巨大になるので、足すたびに 1,000,000 で割った余りを取る。
//       N, K ともに 1〜100。「0 0」で終わる。
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;
int ways[101][101];  // ways[k][n]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 0; n <= 100; n++) ways[1][n] = 1;  // 1個なら n そのものの1通り
    for (int k = 2; k <= 100; k++) {
        for (int n = 0; n <= 100; n++) {
            int sum = 0;
            for (int i = 0; i <= n; i++) {
                sum = (sum + ways[k - 1][n - i]) % MOD;
            }
            ways[k][n] = sum;
        }
    }

    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        cout << ways[k][n] << "\n";
    }
    return 0;
}
