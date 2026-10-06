// CPE26052 Pi (UVa 412)
// 考え方: 全ての組 (i, j) (i < j) を調べ、最大公約数が 1 の組を数える（互いに素）。
//         互いに素な組の割合 = 6 / π² なので、π = √(6 × 全組数 / 互いに素な組数)。
// 計算量: O(N² log 値) / データ。N < 50 なので十分速い。
// 注意: 互いに素な組が 0 個のときは割り算できないので "No estimate for this data set." を出す。
//       小数は printf("%.6f") で小数第6位まで。入力は N = 0 で終わる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int total = 0;     // 全ての組の数
        int coprime = 0;   // 互いに素な組の数
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                total++;
                if (__gcd(a[i], a[j]) == 1) coprime++;
            }
        }

        if (coprime == 0) {
            printf("No estimate for this data set.\n");
        } else {
            printf("%.6f\n", sqrt(6.0 * total / coprime));
        }
    }
    return 0;
}
