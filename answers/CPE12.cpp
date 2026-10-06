// CPE12 Rotating Sentences (UVa 490)
// 考え方: 全行を読んで最長の長さ maxLen を求める。
//         出力の j 行目は「最後の文の j 文字目, …, 最初の文の j 文字目」を並べたもの。
//         文が短くて j 文字目がない場合は空白で埋める。
// 計算量: O(行数 × maxLen)
// 注意: 文中の空白も1文字なので getline で読む。足りない文字は空白で埋める。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string s;
    size_t maxLen = 0;
    while (getline(cin, s)) {
        if (!s.empty() && s.back() == '\r') s.pop_back();  // Windows 改行対策
        lines.push_back(s);
        maxLen = max(maxLen, s.size());
    }

    for (size_t j = 0; j < maxLen; j++) {
        for (int i = (int)lines.size() - 1; i >= 0; i--) {
            if (j < lines[i].size()) cout << lines[i][j];
            else cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}
