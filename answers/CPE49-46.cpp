// CPE49-46 Eb Alto Saxophone Player (UVa 10415)
// 考え方: 音ごとに「どの指（1〜10）を使うか」を表にしておく。
//         各音で、使う指のうち「直前の音では使っていなかった指」の押した回数を +1 する。
//         最初の音は、使う指すべてが押したことになる（直前は何も押していない状態）。
// 計算量: 1曲 O(音の数 × 10)
// 注意: 曲は空のこともある（全部 0 を出力）。getline で1行ずつ読む。
//       指の表は問題文の 2~4 = 2,3,4 のように範囲で書かれている（md では (cid:24) が ~）。
#include <bits/stdc++.h>
using namespace std;

// table[音] = その音で使う指の番号（1〜10）
map<char, vector<int>> table = {
    {'c', {2, 3, 4, 7, 8, 9, 10}},
    {'d', {2, 3, 4, 7, 8, 9}},
    {'e', {2, 3, 4, 7, 8}},
    {'f', {2, 3, 4, 7}},
    {'g', {2, 3, 4}},
    {'a', {2, 3}},
    {'b', {2}},
    {'C', {3}},
    {'D', {1, 2, 3, 4, 7, 8, 9}},
    {'E', {1, 2, 3, 4, 7, 8}},
    {'F', {1, 2, 3, 4, 7}},
    {'G', {1, 2, 3, 4}},
    {'A', {1, 2, 3}},
    {'B', {1, 2}},
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    string line;
    getline(cin, line);  // t の行の残り（改行）を読み捨てる

    while (t--) {
        getline(cin, line);

        int press[11] = {0};
        bool prev[11] = {false};  // 直前の音で使っていた指

        for (char ch : line) {
            if (table.count(ch) == 0) continue;  // '\r' などは無視
            bool now[11] = {false};
            for (int f : table[ch]) now[f] = true;
            for (int f = 1; f <= 10; f++) {
                if (now[f] && !prev[f]) press[f]++;
                prev[f] = now[f];
            }
        }

        for (int f = 1; f <= 10; f++) {
            cout << press[f] << (f == 10 ? "\n" : " ");
        }
    }

    return 0;
}
