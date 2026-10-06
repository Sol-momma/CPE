// CPE16 What is the Probability? (UVa 10056)
// 考え方: q = 1 - p とする。I 番目の人が1周目で勝つ確率は q^(I-1) * p。
//         誰も当たらずに1周する確率は q^N なので、何周目でも勝てるように等比級数で足すと
//         答え = q^(I-1) * p / (1 - q^N)。
// 計算量: O(1) / ケース
// 注意: p = 0 だと分母が 0 になるので、答えを 0.0000 にする。
//       出力は小数点以下4桁。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;
    cin >> s;
    cout << fixed << setprecision(4);
    while (s--) {
        int n, i;
        double p;
        cin >> n >> p >> i;

        double ans = 0.0;
        if (p > 0) {
            double q = 1.0 - p;
            ans = pow(q, i - 1) * p / (1.0 - pow(q, n));
        }
        cout << ans << "\n";
    }

    return 0;
}
