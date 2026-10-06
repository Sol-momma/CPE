// CPE26024 Find the Telephone (UVa 10921)
// 考え方: 各文字を電話のキー番号に置き換える。英大文字は表の数字に、「-」「1」「0」はそのまま。
//         26文字ぶんの対応を文字列 "22233344455566677778889999" にしておけば、c - 'A' で引ける。
// 計算量: O(文字数)
// 注意: 入力は EOF まで（行数は不明）。行ごとに getline で読む。ハイフンも出力に残す。
#include <bits/stdc++.h>
using namespace std;

int main() {
    // A,B,C→2  D,E,F→3  G,H,I→4  J,K,L→5  M,N,O→6  P,Q,R,S→7  T,U,V→8  W,X,Y,Z→9
    const string key = "22233344455566677778889999";
    string line;
    while (getline(cin, line)) {
        string out = "";
        for (char c : line) {
            if (c >= 'A' && c <= 'Z') {
                out += key[c - 'A'];
            } else {
                out += c;
            }
        }
        cout << out << "\n";
    }
    return 0;
}
