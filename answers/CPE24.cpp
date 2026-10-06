// CPE24 Back to High School Physics (UVa 10071)
// 考え方: 等加速度運動で、時刻 t の速度が v のとき、時刻 2t までの変位は 2 * v * t になる。
//         （変位 = 平均速度 × 時間。0〜2t の平均速度は、ちょうど中間の時刻 t の速度 v と等しい）
// 計算量: O(1) / 行
// 注意: v は負の場合もある。入力は EOF まで。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, t;
    while (cin >> v >> t) {
        cout << 2 * v * t << "\n";
    }

    return 0;
}
