// CPE26-041 Zapping (UVa 12468)
// 考え方: チャンネルは 0〜99 の輪になっている。上に進む回数と下に進む回数のうち、少ない方が答え。
//         差を d = |a - b| とすると、直接行くのが d 回、反対回りが 100 - d 回。
// 計算量: O(1) / 行
// 注意: 終わりは「-1 -1」。a == b のときは 0 回。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b) {
        if (a == -1 && b == -1) break;

        int d = abs(a - b);
        cout << min(d, 100 - d) << "\n";
    }
    return 0;
}
