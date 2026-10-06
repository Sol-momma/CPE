// CPE26124 Building designing (UVa 11039)
// 考え方: 大きさ(絶対値)の小さい順に並べ、その中から「色（符号）が交互」になるように選ぶ。
//         並べたとき同じ色が連続している部分は1つしか選べないので、
//         答えは「同じ符号が続くかたまりの数」になる。
// 計算量: O(n log n) / ケース
// 注意: n は最大 500000 なので cin の高速化は必須（sync_with_stdio(false)）。
//       大きさは全部異なるので、絶対値でソートしても同順位の心配はない。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;
    while (p--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });  // 大きさの小さい順

        int floors = 1;  // 1個目は必ず使える
        for (int i = 1; i < n; i++) {
            bool sameColor = (a[i] > 0) == (a[i - 1] > 0);
            if (!sameColor) floors++;  // 色が変わるたびに1階増やせる
        }
        cout << floors << "\n";
    }
    return 0;
}
