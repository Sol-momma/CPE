// CPE26061 Kibbles 'n' Bits 'n' Bits 'n' Bits (UVa 446)
// 考え方: 16進数の文字列を stoi(s, nullptr, 16) で整数にし、足し算か引き算をする。
//         2進数表示は最上位から 1 ビットずつ取り出して、必ず 13 桁（0 埋め）で出力する。
// 計算量: O(N)（1 式あたり定数）
// 注意: 最大は FFF（12ビット）だが、出力は 13 桁固定。AAA + BBB のような足し算の結果は
//       13 ビット目に繰り上がるが、各数は FFF 以下なので 13 桁で足りる。
//       結果は 2 進数ではなく 10 進数で出す。引き算の結果は負にならない。
#include <bits/stdc++.h>
using namespace std;

// x を 13 桁の 2 進数文字列にする
string toBinary13(int x) {
    string s;
    for (int bit = 12; bit >= 0; bit--) {
        s += ((x >> bit) & 1) ? '1' : '0';
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string a, op, b;
        cin >> a >> op >> b;
        int x = stoi(a, nullptr, 16);
        int y = stoi(b, nullptr, 16);
        int result = (op == "+") ? x + y : x - y;
        cout << toBinary13(x) << " " << op << " " << toBinary13(y) << " = " << result << "\n";
    }
    return 0;
}
