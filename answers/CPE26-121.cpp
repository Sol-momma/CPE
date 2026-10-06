// CPE26-121 Flip Sort (UVa 10327)
// 考え方: 隣り合う2つの交換だけで並べ替える最小回数は「逆順になっているペアの数（転倒数）」。
//         i < j かつ a[i] > a[j] のペアを全部数えればよい。
// 計算量: O(N^2) / データ（N ≤ 1000 なので 100万回程度で間に合う）
// 注意: 入力は EOF まで。N の後ろに N 個の整数が続くデータが何組も来る。
//       出力は "Minimum exchange operations : M"（コロンの前後に空白1つずつ）。
//       同じ値は交換不要なので > で数える（>= にしない）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) count++;
            }
        }
        cout << "Minimum exchange operations : " << count << "\n";
    }
    return 0;
}
