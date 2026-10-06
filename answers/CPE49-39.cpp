// CPE49-39 Fourth Point!! (UVa 10242)
// 考え方: 2辺の端点4つのうち、2回出てくる点 P が2辺の共通の頂点。
//         残りの2点を A, B とすると、平行四辺形の4つ目の点は A + B − P。
// 計算量: 1ケース O(1)
// 注意: 共通の点が何番目と何番目かは決まっていない（4通りすべて調べる）。
//       小数点以下3桁で出力。-0.000 と出ないように 0 付近は 0 に直す。
#include <bits/stdc++.h>
using namespace std;

bool samePoint(double x1, double y1, double x2, double y2) {
    return fabs(x1 - x2) < 1e-9 && fabs(y1 - y2) < 1e-9;
}

double fixZero(double v) {
    return fabs(v) < 0.0005 ? 0.0 : v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x[4], y[4];
    while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3]) {
        // 1辺目の端点 i と 2辺目の端点 j が同じ点になる組を探す
        int p = 0, a = 1, b = 3;
        for (int i = 0; i < 2; i++) {
            for (int j = 2; j < 4; j++) {
                if (samePoint(x[i], y[i], x[j], y[j])) {
                    p = i;
                    a = 1 - i;      // 1辺目のもう一方
                    b = 5 - j;      // 2辺目のもう一方（2↔3）
                }
            }
        }

        double fx = x[a] + x[b] - x[p];
        double fy = y[a] + y[b] - y[p];
        cout << fixed << setprecision(3) << fixZero(fx) << " " << fixZero(fy) << "\n";
    }

    return 0;
}
