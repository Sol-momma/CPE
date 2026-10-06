// CPE26034 Counting Chaos (UVa 11309)
// 考え方: 現在時刻の次の分から1分ずつ進めて、回文になる最初の時刻を探す。
//         回文の判定は「HH の先頭の0を消す。HH が 0 なら MM の先頭の0も消す」と問題文どおりの文字列を作って行う。
// 計算量: 最大 1440 分 × 文字列判定 / 行
// 注意: 23:59 の次は 00:00。時刻は 24時間で1周するので % 1440 で戻す。
//       例: 12:21 は "1221" で回文、00:01 は "1" で回文、10:01 は "1001" で回文。
#include <bits/stdc++.h>
using namespace std;

bool isPalindromeTime(int h, int m) {
    string s;
    if (h > 0) {
        s = to_string(h) + (m < 10 ? "0" : "") + to_string(m);  // MM は2桁のまま
    } else {
        s = to_string(m);  // HH が 0 なら MM の先頭の0も消える
    }
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int h, m;
        scanf("%d:%d", &h, &m);

        int t = h * 60 + m;
        while (true) {
            t = (t + 1) % 1440;  // 次の1分
            if (isPalindromeTime(t / 60, t % 60)) break;
        }
        printf("%02d:%02d\n", t / 60, t % 60);
    }
    return 0;
}
