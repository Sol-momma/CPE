// CPE26092 Blocks (UVa 10365)
// 考え方: N 個の立方体で a×b×c = N の直方体を作ると、必要な紙の面積は 2(ab+bc+ca)。
//         a, b を全部試し、c = N/(a*b) が割り切れるときの最小の面積を探す。
// 計算量: O(N^2)/ケース。N ≤ 1000 なので十分間に合う。
// 注意: 立方体に近い形ほど面積が小さいが、公式を考えず全探索したほうが確実。
//       N = 1 のときは 1×1×1 で答えは 6。
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
        int best = INT_MAX;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; a * b <= n; b++) {
                if (n % (a * b) != 0) continue;  // c が整数にならない組は捨てる
                int c = n / (a * b);
                best = min(best, 2 * (a * b + b * c + c * a));
            }
        }
        cout << best << "\n";
    }
    return 0;
}
