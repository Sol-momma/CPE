// CPE49-08 What's Cryptanalysis? (UVa 10008)
// 考え方: 英字だけを大文字にそろえて A〜Z の出現回数を数える。
//         回数の多い順（同数ならアルファベット順）に並べて、1回以上のものだけ出力。
// 計算量: O(文字数 + 26 log 26)
// 注意: 1行目の n を読んだあと、改行が残るので getline の前に読み捨てる。
//       行には空白や記号も含まれるので getline で1行まるごと読む。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string line;
    getline(cin, line);  // n の後ろの改行を読み捨てる

    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        for (char c : line) {
            if (isalpha((unsigned char)c)) cnt[toupper(c) - 'A']++;
        }
    }

    vector<pair<int, char>> v;  // (回数, 文字)
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) v.push_back({cnt[i], (char)('A' + i)});
    }
    sort(v.begin(), v.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        if (a.first != b.first) return a.first > b.first;  // 回数の多い順
        return a.second < b.second;                         // 同数ならアルファベット順
    });

    for (auto& p : v) cout << p.second << " " << p.first << "\n";
    return 0;
}
