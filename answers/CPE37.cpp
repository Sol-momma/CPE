// CPE37 Satellites (UVa 10221)
// 考え方: 衛星は地球の中心から r = 6440 + s の円周上にある。
//         中心角 a（度）から 弧 = r * a(ラジアン)、弦 = 2 * r * sin(a/2) で求まる。
//         'min'（分）なら 60 で割って度に直す。180 度を超える角は 360 - a にする（近い側を測る）。
// 計算量: 1ケース O(1)
// 注意: 小数点以下6桁。角度は分の場合もある。a > 180 のときの処理を忘れやすい。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double EARTH = 6440.0;
    const double PI = acos(-1.0);

    double s, a;
    string unit;
    while (cin >> s >> a >> unit) {
        if (unit == "min") a /= 60.0;
        if (a > 180.0) a = 360.0 - a;

        double r = EARTH + s;
        double rad = a * PI / 180.0;
        double arc = r * rad;
        double chord = 2.0 * r * sin(rad / 2.0);

        cout << fixed << setprecision(6) << arc << " " << chord << "\n";
    }

    return 0;
}
