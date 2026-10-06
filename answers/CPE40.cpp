// CPE40 A mid-summer night's dream (UVa 10057)
// 考え方: |X1−A| + … + |Xn−A| を最小にする A は「中央値」。ソートして真ん中を見る。
//         n が奇数: 中央値はちょうど1つ（a[n/2]）。
//         n が偶数: a[n/2−1] 以上 a[n/2] 以下の整数ならどれでも最小になる。
//         出力は (最小の A) (入力のうち条件を満たす数の個数) (A になれる整数の個数)。
// 計算量: O(n log n)（ソート）
// 注意: n は最大 10^6 なので、全ての A を試す方法では間に合わない。ソートして中央値を使う。
//       2つ目の値は「入力の中で lo〜hi の範囲に入っている数の個数」（同じ値も重複して数える）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int lo, hi;
        if (n % 2 == 1) {
            lo = hi = a[n / 2];
        } else {
            lo = a[n / 2 - 1];
            hi = a[n / 2];
        }

        int cnt = 0;
        for (int v : a) {
            if (lo <= v && v <= hi) cnt++;
        }

        cout << lo << " " << cnt << " " << hi - lo + 1 << "\n";
    }

    return 0;
}
