// CPE42 Train Swapping (UVa 299)
// 考え方: 隣どうしの入れ替えだけで並べる最少回数 = バブルソートで入れ替えた回数
//         （= 「前にあるのに自分より大きい数」の組の個数＝転倒数）。
// 計算量: 1ケース O(L^2)（L ≤ 50 なので十分速い）
// 注意: 出力は 1 回でも "swaps."（複数形のまま）。L = 0 の場合もある。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int L;
        cin >> L;
        vector<int> a(L);
        for (int i = 0; i < L; i++) cin >> a[i];

        int swaps = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j + 1 < L - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swaps++;
                }
            }
        }

        cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }

    return 0;
}
