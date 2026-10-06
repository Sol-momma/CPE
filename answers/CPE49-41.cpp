// CPE49-41 Tell me the frequencies! (UVa 10062)
// 考え方: 1行ごとに、各文字の出現回数を配列 cnt[文字コード] で数える。
//         (回数, 文字コード) の組を「回数が少ない順、同じなら文字コードが大きい順」に並べて出力。
// 計算量: 1行 O(L + 128 log 128)
// 注意: 出力は「文字そのもの」ではなく ASCII の番号。
//       出力のまとまりの「間」に空行（最後には付けない）。行末の '\r' は数えない。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    bool first = true;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();

        int cnt[128] = {0};
        for (char ch : line) {
            int c = (unsigned char)ch;
            if (c < 128) cnt[c]++;
        }

        vector<pair<int, int>> v;  // (回数, 文字コード)
        for (int c = 0; c < 128; c++) {
            if (cnt[c] > 0) v.push_back({cnt[c], c});
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& p, const pair<int, int>& q) {
            if (p.first != q.first) return p.first < q.first;  // 回数が少ない順
            return p.second > q.second;                        // 同じなら文字コードが大きい順
        });

        if (!first) cout << "\n";
        first = false;
        for (auto& p : v) cout << p.second << " " << p.first << "\n";
    }

    return 0;
}
