// CPE26-111 Binomial Showdown (UVa 530)
// 考え方: C(n,k) を「掛けて割る」を1回ずつ繰り返して求める。
//         r = r * (n-k+i) / i を i=1..k で回すと、各段階の r は C(n-k+i, i) になり、必ず割り切れる。
// 計算量: O(k) / 行
// 注意: n! を直接計算すると桁あふれする。途中の r*(n-k+i) は int を超えるので long long を使う。
//       C(n,k) = C(n,n-k) なので k を小さい方に取ると、ループ回数も途中の値も小さくて済む。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;  // 「0 0」は終わりの合図

        if (k > n - k) k = n - k;  // 小さい方を使う

        long long r = 1;
        for (long long i = 1; i <= k; i++) {
            r = r * (n - k + i) / i;  // 先に掛けてから割る（割り切れる順序）
        }
        cout << r << "\n";
    }
    return 0;
}
