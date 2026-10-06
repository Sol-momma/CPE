// CPE07 List of Conquests (UVa 10420)
// 考え方: 各行の最初の単語（国名）だけを数える。map<string,int> に入れると
//         自動でアルファベット順に並ぶので、そのまま出力すればよい。
// 計算量: O(n log n)
// 注意: 名前の部分（2単語目以降）は使わないが、行の残りを getline で読み捨てる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string country, rest;
        cin >> country;
        getline(cin, rest);  // 女性の名前（使わない）
        cnt[country]++;
    }

    for (auto& p : cnt) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
