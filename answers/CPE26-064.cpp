// CPE26-064 Fibonaccimal Base (UVa 948)
// 考え方: フィボナッチ数 1, 2, 3, 5, 8, ... を作っておく。大きい方から順に、引けるなら引いて
//         その桁に 1、引けないなら 0 を書く（貪欲法）。こうすると連続する 1 は現れず、答えは一意。
// 計算量: O(フィボナッチ数の個数) / 数 ≒ 40
// 注意: 桁は 1, 2, 3, 5, ... に対応する（0, 1, 1, 2, ... の最初の 0 と重複する 1 は使わない）。
//       先頭の 0 は書かない。出力は "元の数 = 結果 (fib)"。n < 100000000 なので int で足りる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> fib = {1, 2};
    while (fib.back() < 100000000) {
        int k = fib.size();
        fib.push_back(fib[k - 1] + fib[k - 2]);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        int rest = n;
        for (int i = (int)fib.size() - 1; i >= 0; i--) {
            if (fib[i] <= rest) {
                s += '1';
                rest -= fib[i];
            } else if (!s.empty()) {
                s += '0';  // 先頭の 0 は書かない
            }
        }
        cout << n << " = " << s << " (fib)\n";
    }
    return 0;
}
