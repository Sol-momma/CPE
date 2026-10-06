// CPE01 Vito's Family (UVa 10041)
// 考え方: 距離の合計 |s1-x| + |s2-x| + ... が最小になる x は「中央値」。
//         番地をソートして真ん中の値を家の位置にし、各親戚との距離を足す。
// 計算量: O(r log r)（ソート）
// 注意: 親戚が偶数人なら真ん中2つのどちらを選んでも合計は同じ。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        vector<int> s(r);
        for (int i = 0; i < r; i++) cin >> s[i];

        sort(s.begin(), s.end());
        int home = s[r / 2];  // 中央値

        long long total = 0;
        for (int i = 0; i < r; i++) total += abs(s[i] - home);
        cout << total << "\n";
    }
    return 0;
}
