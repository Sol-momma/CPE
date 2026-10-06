// CPE26101 Cantor Fractions (UVa 880)
// 考え方: 分数は「斜めの列」ごとに並ぶ。d 番目の斜めには d 個の分数があり、
//         その k 番目は 分子 = d-k+1、分母 = k。i から斜めの列の大きさを引いていき、
//         どの斜め列の何番目かを求める。
// 計算量: O(√i)/ケース
// 注意: 約分はしない（2/2 などもそのまま出す）。i は int に収まらない可能性に備えて long long。
//       入力は EOF まで続く。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long i;
    while (cin >> i) {
        long long d = 1;  // 今見ている斜め列（この列には d 個ある）
        while (i > d) {
            i -= d;
            d++;
        }
        // i は d 列目の中で何番目か（1〜d）
        cout << d - i + 1 << "/" << i << "\n";
    }
    return 0;
}
