// CPE26-133 Simply Subsets (UVa 496)
// 考え方: 2行ずつ読んで集合 A, B にし、共通する要素の数を数えて関係を決める。
//         共通数 c、A の大きさ a、B の大きさ b として
//         a==b==c → 等しい / c==a(<b) → A が真部分集合 / c==b(<a) → B が真部分集合 /
//         c==0 → 共通なし / それ以外 → confused。
// 計算量: O(行の長さ log 行の長さ)
// 注意: 判定の順番が大事。「等しい」を先に調べないと「部分集合」に入ってしまう。
//       入力は EOF まで、2行1組で続く。数字の個数は行ごとに違うので getline で1行読んで切り分ける。
#include <bits/stdc++.h>
using namespace std;

set<int> readSet(const string& line) {
    set<int> s;
    istringstream iss(line);
    int x;
    while (iss >> x) s.insert(x);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string la, lb;
    while (getline(cin, la) && getline(cin, lb)) {
        set<int> A = readSet(la);
        set<int> B = readSet(lb);

        int common = 0;  // 共通する要素の数
        for (int x : A) {
            if (B.count(x)) common++;
        }
        int a = A.size();
        int b = B.size();

        if (a == b && common == a) {
            cout << "A equals B\n";
        } else if (common == a) {
            cout << "A is a proper subset of B\n";
        } else if (common == b) {
            cout << "B is a proper subset of A\n";
        } else if (common == 0) {
            cout << "A and B are disjoint\n";
        } else {
            cout << "I'm confused!\n";
        }
    }
    return 0;
}
