// CPE26-134 Antiarithmetic? (UVa 10730)
// 考え方: 等差数列 (a, m, b) は a + b = 2m、つまり m を真ん中にして m-d と m+d の組。
//         各値 m と各 d について、m-d と m+d の位置を調べ、
//         「m の左右に1つずつ分かれている」なら等差数列が見つかったことになる。
//         値から位置を引ける配列 pos を作っておくと簡単に調べられる。
// 計算量: O(n^2)（見つかった時点で打ち切る）
// 注意: 入力は "3: 0 2 1" のように n のあとに ':' が付く。n=0 で終わり。
//       値は 0〜n-1 の順列なので、m-d >= 0 かつ m+d <= n-1 の範囲だけ調べる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        char colon;
        cin >> colon;  // ':' を読み飛ばす

        vector<int> pos(n);  // pos[値] = その値が出てくる位置
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            pos[v] = i;
        }

        bool anti = true;
        for (int m = 0; m < n && anti; m++) {
            for (int d = 1; m - d >= 0 && m + d < n; d++) {
                // m-d と m+d が m の反対側にあれば、(m-d, m, m+d) か逆順が部分列になる
                bool leftBefore = pos[m - d] < pos[m];
                bool rightBefore = pos[m + d] < pos[m];
                if (leftBefore != rightBefore) {
                    anti = false;
                    break;
                }
            }
        }
        cout << (anti ? "yes" : "no") << "\n";
    }
    return 0;
}
