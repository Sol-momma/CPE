// CPE26-091 Points in Figures: Rectangles, Circles, and Triangles (UVa 478)
// 考え方: 図形を読み込んで保存し、各点について図形ごとに「内側か」を判定する。
//         長方形は x と y が範囲の内側、円は中心までの距離^2 < r^2、
//         三角形は3辺それぞれに対して点が同じ側にあるか（外積の符号）で調べる。
// 計算量: O(点の数 × 図形の数)（図形は10個以下）
// 注意: 境界上の点は「内側ではない」ので、すべて < や > の厳密な比較にする。
//       円の判定は sqrt を使わず距離の2乗どうしで比べると誤差が出にくい。
//       図形の番号・点の番号はどちらも入力順で 1 から数える。
#include <bits/stdc++.h>
using namespace std;

struct Figure {
    char type;       // 'r' 'c' 't'
    double v[6];     // 図形を表す数値（種類によって使う個数が違う）
};

// 点 (px,py) が三角形 (ax,ay)-(bx,by)-(cx,cy) の内側か
bool inTriangle(double px, double py, const double* v) {
    // 辺 a->b の「どちら側にいるか」は外積の符号でわかる
    double d1 = (v[2] - v[0]) * (py - v[1]) - (v[3] - v[1]) * (px - v[0]);
    double d2 = (v[4] - v[2]) * (py - v[3]) - (v[5] - v[3]) * (px - v[2]);
    double d3 = (v[0] - v[4]) * (py - v[5]) - (v[1] - v[5]) * (px - v[4]);
    // 3つとも正、または3つとも負なら内側（0 は辺の上なので除く）
    return (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
}

bool contains(const Figure& f, double x, double y) {
    if (f.type == 'r') {
        double left = min(f.v[0], f.v[2]), right = max(f.v[0], f.v[2]);
        double low = min(f.v[1], f.v[3]), high = max(f.v[1], f.v[3]);
        return left < x && x < right && low < y && y < high;
    }
    if (f.type == 'c') {
        double dx = x - f.v[0], dy = y - f.v[1];
        return dx * dx + dy * dy < f.v[2] * f.v[2];
    }
    return inTriangle(x, y, f.v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Figure> figs;
    string s;
    while (cin >> s && s != "*") {
        Figure f;
        f.type = s[0];
        int need = (f.type == 'r') ? 4 : (f.type == 'c') ? 3 : 6;
        for (int i = 0; i < need; i++) cin >> f.v[i];
        figs.push_back(f);
    }

    double x, y;
    int no = 0;
    while (cin >> x >> y) {
        if (x == 9999.9 && y == 9999.9) break;  // 終わりの合図
        no++;
        bool any = false;
        for (int j = 0; j < (int)figs.size(); j++) {
            if (contains(figs[j], x, y)) {
                cout << "Point " << no << " is contained in figure " << j + 1 << "\n";
                any = true;
            }
        }
        if (!any) cout << "Point " << no << " is not contained in any figure\n";
    }
    return 0;
}
