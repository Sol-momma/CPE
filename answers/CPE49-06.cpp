// CPE49-06 Bangla Numbers (UVa 10101)
// ※ 問題文ファイルが誤っているため UVa 10101 の内容に基づく（問題文未確認）
// 考え方: ベンガル式の単位 kuti(10^7), lakh(10^5), hajar(10^3), shata(10^2) で区切って読む。
//         kuti より上の部分（num / 10^7）も同じ規則で読むので、再帰で書くと短い。
// 計算量: O(log n) / 行
// 注意: 行番号は4桁右寄せ（"%4d."）。0 のときは " 0" を出力する。
//       入力は 10^15 程度まであるので long long。EOF まで読む。
#include <bits/stdc++.h>
using namespace std;

void say(long long num) {
    if (num >= 10000000) {
        say(num / 10000000);
        cout << " kuti";
        num %= 10000000;
    }
    if (num >= 100000) {
        say(num / 100000);
        cout << " lakh";
        num %= 100000;
    }
    if (num >= 1000) {
        say(num / 1000);
        cout << " hajar";
        num %= 1000;
    }
    if (num >= 100) {
        say(num / 100);
        cout << " shata";
        num %= 100;
    }
    if (num != 0) cout << " " << num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long num;
    int caseNo = 1;
    while (cin >> num) {
        cout << setw(4) << caseNo << ".";
        if (num == 0) cout << " 0";
        else say(num);
        cout << "\n";
        caseNo++;
    }
    return 0;
}
