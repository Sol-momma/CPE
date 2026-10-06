// CPE26-122 Shopaholic (UVa 11369)
// 考え方: 3個ずつ組にして、一番安いものが無料。無料にできる値を最大にするには、
//         値段を高い順に並べて、3個目・6個目・9個目…（添字 2, 5, 8, …）を無料にする。
//         高いもの同士でまとめるほど、「3番目に高い」ものが無駄なく無料になる。
// 計算量: O(n log n) / シナリオ
// 注意: 3個未満の余りには割引がない。合計は最大 20000 × 20000 / 3 程度だが long long にしておく。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        sort(p.begin(), p.end(), greater<int>());  // 高い順

        long long discount = 0;
        for (int i = 2; i < n; i += 3) {
            discount += p[i];
        }
        cout << discount << "\n";
    }
    return 0;
}
