// CPE26-103 Ant on a Chessboard (UVa 10161)
// 考え方: 時刻 N は「k×k の正方形を最後に埋める L 字の層」のどこかにある。
//         k は k^2 ≥ N となる最小の k。層の中で m = N-(k-1)^2 番目（1〜2k-1）として位置を決める。
//         k が奇数なら (k,1) から上へ、その後 左へ。k が偶数なら (1,k) から右へ、その後 下へ。
// 計算量: O(1)/行
// 注意: N は 2×10^9 まであるので long long。k の計算は sqrt の誤差を while で直す。
//       出力は「列 行」つまり「x y」の順。入力は 0 で終了。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n && n != 0) {
        long long k = (long long)sqrt((double)n);
        while (k * k < n) k++;      // k^2 >= n になる最小の k にそろえる
        while (k > 1 && (k - 1) * (k - 1) >= n) k--;

        long long m = n - (k - 1) * (k - 1);  // 層の中で何番目か
        long long x, y;
        if (k % 2 == 1) {
            if (m <= k) {
                x = k;
                y = m;
            } else {
                x = k - (m - k);
                y = k;
            }
        } else {
            if (m <= k) {
                x = m;
                y = k;
            } else {
                x = k;
                y = k - (m - k);
            }
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}
