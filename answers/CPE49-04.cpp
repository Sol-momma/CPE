// CPE49-04 The 3n+1 problem (UVa 100)
// 考え方: i〜j の各数について、問題文の手順（奇数なら 3n+1、偶数なら n/2）を
//         1 になるまで繰り返し、出力された個数（cycle length）を数えて最大を取る。
// 計算量: O((j-i+1) × cycle length)。値は 10000 未満なので十分間に合う。
// 注意: i > j の入力もある。範囲は小さい方〜大きい方で回すが、出力は入力の順のまま。
//       途中の値は int を超えうるので long long で計算する。
#include <bits/stdc++.h>
using namespace std;

int cycleLength(long long n) {
    int len = 1;  // 最初の n も数える
    while (n != 1) {
        if (n % 2 == 1) n = 3 * n + 1;
        else n = n / 2;
        len++;
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, j;
    while (cin >> i >> j) {
        int lo = min(i, j), hi = max(i, j);
        int best = 0;
        for (int n = lo; n <= hi; n++) best = max(best, cycleLength(n));
        cout << i << " " << j << " " << best << "\n";
    }
    return 0;
}
