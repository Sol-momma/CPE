// CPE15 Jolly Jumpers (UVa 10038)
// 考え方: 隣り合う要素の差の絶対値を計算し、1〜n-1 がすべてちょうど1回ずつ出るか調べる。
//         差は n-1 個あるので、範囲外の値や重複が1つでもあれば Not jolly。
// 計算量: O(n) / 行
// 注意: n = 1 は常に Jolly。差は int を超えうるので long long で計算する。
//       入力は EOF まで続く。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<bool> seen(n, false);  // seen[k] = 差 k が出たか
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            long long diff = llabs(a[i] - a[i - 1]);
            if (diff < 1 || diff > n - 1 || seen[diff]) {
                jolly = false;
                break;
            }
            seen[diff] = true;
        }

        cout << (jolly ? "Jolly" : "Not jolly") << "\n";
    }

    return 0;
}
