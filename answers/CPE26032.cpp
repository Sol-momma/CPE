// CPE26032 Cancer or Scorpio (UVa 11947)
// 考え方: 最後の生理開始日に 40週 = 280日 を足した日が出産日。
//         1日ずつ日付を進め（月末・年末・うるう年に注意）、星座表と見比べる。
// 計算量: O(280) / 行
// 注意: うるう年は 4で割れる年。ただし 100で割れる年は平年で、400で割れる年はうるう年。
//       星座は (月, 日) の境目で決まる。山羊座だけ年またぎ（12/23〜1/20）。
#include <bits/stdc++.h>
using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int daysInMonth(int y, int m) {
    int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) return 29;
    return d[m];
}

// 月日から星座名を返す
string zodiac(int m, int d) {
    int md = m * 100 + d;  // 1月21日 → 121 のように比べやすくする
    if (md >= 121 && md <= 219) return "aquarius";
    if (md >= 220 && md <= 320) return "pisces";
    if (md >= 321 && md <= 420) return "aries";
    if (md >= 421 && md <= 521) return "taurus";
    if (md >= 522 && md <= 621) return "gemini";
    if (md >= 622 && md <= 722) return "cancer";
    if (md >= 723 && md <= 821) return "leo";
    if (md >= 822 && md <= 923) return "virgo";
    if (md >= 924 && md <= 1023) return "libra";
    if (md >= 1024 && md <= 1122) return "scorpio";
    if (md >= 1123 && md <= 1222) return "sagittarius";
    return "capricorn";  // 12/23〜1/20
}

int main() {
    int n;
    scanf("%d", &n);
    for (int no = 1; no <= n; no++) {
        int mmddyyyy;
        scanf("%d", &mmddyyyy);
        int m = mmddyyyy / 1000000;
        int d = mmddyyyy / 10000 % 100;
        int y = mmddyyyy % 10000;

        for (int i = 0; i < 280; i++) {  // 1日ずつ進める
            d++;
            if (d > daysInMonth(y, m)) {
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                }
            }
        }

        printf("%d %02d/%02d/%04d %s\n", no, m, d, y, zodiac(m, d).c_str());
    }
    return 0;
}
