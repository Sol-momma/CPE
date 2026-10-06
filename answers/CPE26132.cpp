// CPE26132 Cool Word (UVa 12820)
// 考え方: 各文字の出現回数を数える。出現した文字の種類が2つ以上あり、
//         その出現回数がすべて異なれば cool word。
//         回数どうしの重なりは「同じ回数を2回見たら失格」で判定する。
// 計算量: O(全単語の文字数)
// 注意: 文字の種類が1つだけ（例 "aaa"）は cool ではない。
//       出力は "Case 1: 1" の形。ケースごとに番号を増やす。入力は EOF まで複数ケースが続く。
#include <bits/stdc++.h>
using namespace std;

bool isCool(const string& w) {
    int cnt[26] = {0};
    for (char c : w) cnt[c - 'a']++;

    int kinds = 0;                // 文字の種類数
    bool used[31] = {false};      // その回数を、すでに別の文字が使っているか（最大30文字）
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        kinds++;
        if (used[cnt[i]]) return false;  // 同じ回数が2つある
        used[cnt[i]] = true;
    }
    return kinds >= 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int caseNo = 0;
    while (cin >> n) {
        int coolCount = 0;
        for (int i = 0; i < n; i++) {
            string w;
            cin >> w;
            if (isCool(w)) coolCount++;
        }
        caseNo++;
        cout << "Case " << caseNo << ": " << coolCount << "\n";
    }
    return 0;
}
