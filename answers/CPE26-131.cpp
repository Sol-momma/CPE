// CPE26-131 Word Amalgamation (UVa 642)
// 考え方: 「並べ替えて作れる単語」＝「文字を並べ替えた形（文字をソートした文字列）が同じ単語」。
//         辞書の各単語を、ソートした文字列をキーにして覚えておく。
//         ぐちゃぐちゃ単語もソートして、同じキーの辞書単語を探す。
// 計算量: O(辞書の語数 × 問い合わせ数 × 6 log 6)
// 注意: 辞書単語はアルファベット順に出力する。0個なら "NOT A VALID WORD"。
//       どちらの場合も最後に "******" を出す。終端の "XXXXXX" は2回出てくる（辞書の終わりと全体の終わり）。
#include <bits/stdc++.h>
using namespace std;

// 文字をソートした文字列（並べ替えても同じになる「しるし」）
string keyOf(string s) {
    sort(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> dict;
    string w;
    while (cin >> w && w != "XXXXXX") {
        dict.push_back(w);
    }
    sort(dict.begin(), dict.end());  // 先に並べておけば、見つけた順がそのままアルファベット順

    while (cin >> w && w != "XXXXXX") {
        string key = keyOf(w);
        bool found = false;
        for (const string& d : dict) {
            if (keyOf(d) == key) {
                cout << d << "\n";
                found = true;
            }
        }
        if (!found) cout << "NOT A VALID WORD\n";
        cout << "******\n";
    }
    return 0;
}
