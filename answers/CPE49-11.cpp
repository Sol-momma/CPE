// CPE49-11 Common Permutation (UVa 10252)
// 考え方: a と b それぞれで 'a'〜'z' の出現回数を数える。
//         各文字について min(aの回数, bの回数) 個ずつ、a→z の順に並べれば答え。
// 計算量: O(|a| + |b|)
// 注意: 空行（長さ0の文字列）が来ることがあるので cin >> ではなく getline で読む。
//       その場合は空行を出力する。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        int ca[26] = {0}, cb[26] = {0};
        for (char c : a) if (islower((unsigned char)c)) ca[c - 'a']++;
        for (char c : b) if (islower((unsigned char)c)) cb[c - 'a']++;

        string x;
        for (int i = 0; i < 26; i++) {
            x += string(min(ca[i], cb[i]), (char)('a' + i));
        }
        cout << x << "\n";
    }
    return 0;
}
