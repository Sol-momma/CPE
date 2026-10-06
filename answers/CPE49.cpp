// CPE49 Sort! Sort!! and Sort!!! (UVa 11321)
// 考え方: sort に「比べ方（比較関数）」を渡して、問題の規則どおりに並べる。
//         1. x % M が小さい順
//         2. 同じなら 奇数が先
//         3. 両方奇数なら 大きい方が先、両方偶数なら 小さい方が先
// 計算量: 1セット O(N log N)
// 注意: 負の数の余りは C++ の % と同じ（-100 % 3 = -1）なので、そのまま % を使えばよい。
//       負の奇数は x % 2 が -1 になるので、奇数判定は x % 2 != 0 で書く（== 1 だと誤り）。
//       最後の "0 0" も出力する。
#include <bits/stdc++.h>
using namespace std;

int M;

bool isOdd(int x) {
    return x % 2 != 0;
}

bool cmp(int a, int b) {
    int ra = a % M, rb = b % M;
    if (ra != rb) return ra < rb;
    if (isOdd(a) && !isOdd(b)) return true;    // 奇数が先
    if (!isOdd(a) && isOdd(b)) return false;
    if (isOdd(a)) return a > b;                // 両方奇数: 大きい方が先
    return a < b;                              // 両方偶数: 小さい方が先
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n >> M) {
        cout << n << " " << M << "\n";
        if (n == 0 && M == 0) break;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), cmp);

        for (int v : a) cout << v << "\n";
    }

    return 0;
}
