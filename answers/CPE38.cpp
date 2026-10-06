// CPE38 Can You Solve It? (UVa 10642)
// 考え方: 円は (0,0)→(0,1)→(1,0)→(0,2)→(1,1)→(2,0)→… と斜めの列ごとに並んでいる。
//         (x, y) は d = x + y 番目の斜め列にあり、それより前の列に 1+2+…+d = d(d+1)/2 個ある。
//         その列の中では x 番目なので、通し番号は d(d+1)/2 + x。
//         答えは「目的地の番号 − 出発地の番号」。
// 計算量: 1ケース O(1)
// 注意: 座標は最大 100000 なので番号は約 2×10^10。int では溢れるので long long。
//       出力は "Case 1: 3" の形式。
#include <bits/stdc++.h>
using namespace std;

long long indexOf(long long x, long long y) {
    long long d = x + y;
    return d * (d + 1) / 2 + x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Case " << t << ": " << indexOf(x2, y2) - indexOf(x1, y1) << "\n";
    }

    return 0;
}
