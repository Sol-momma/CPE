// CPE26-051 Count the factors (UVa 10699)
// 考え方: n を 2, 3, 4, ... で順に割っていく。割り切れたら、その素数が1種類見つかったと数え、
//         割り切れる間は割り続けて消す（同じ素数を2回数えないため）。
// 計算量: O(√n) / 行（n ≤ 1000000 なので √n ≤ 1000）
// 注意: 最後に 1 より大きい数が残ったら、それ自体が最後の素数なので +1。
//       n = 1 の素数は 0 個。出力は "n : 個数" の形（コロンの前後に空白）。入力は 0 で終わり。
#include <bits/stdc++.h>
using namespace std;

// n の異なる素因数の個数を返す
int countPrimeFactors(int n) {
    int count = 0;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            count++;
            while (n % p == 0) n /= p;  // この素数を使い切る
        }
    }
    if (n > 1) count++;  // 残りは大きな素数1つ
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << n << " : " << countPrimeFactors(n) << "\n";
    }
    return 0;
}
