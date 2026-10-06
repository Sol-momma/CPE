// CPE49-43 Hardwood Species (UVa 10226)
// 考え方: 木の名前を1行ずつ読み、map<string,int> で本数を数える。
//         map は名前のアルファベット順に並ぶので、そのまま順に「本数 / 全体 × 100」を出力。
// 計算量: 1ケース O(N log K)（N: 木の本数 ≤ 10^6、K: 種類数）
// 注意: 名前に空白が入る（"Red Alder"）ので cin >> ではなく getline で1行ずつ読む。
//       ケースは空行で区切られている。出力もケースの「間」に空行。小数点以下4桁。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    int T = stoi(line);
    getline(cin, line);  // テストケース数のあとの空行

    for (int t = 0; t < T; t++) {
        map<string, int> cnt;
        int total = 0;
        while (getline(cin, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            if (line.empty()) break;  // 空行 = このケースの終わり
            cnt[line]++;
            total++;
        }

        if (t > 0) cout << "\n";
        for (auto& p : cnt) {
            cout << p.first << " " << fixed << setprecision(4) << p.second * 100.0 / total << "\n";
        }
    }

    return 0;
}
