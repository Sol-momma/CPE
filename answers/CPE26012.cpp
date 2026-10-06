// CPE26012 Dates (UVa 11356)
// 考え方: 日付を「1日ずつ進める」を K 回くり返す。K < 10000 なので十分速い。
//         日を +1 して、その月の日数を超えたら月を進め、12月を超えたら年を進める。
// 計算量: O(K) / ケース
// 注意: うるう年は「4で割り切れる、ただし100で割り切れるなら400でも割り切れるときだけ」。
//       出力は yyyy-Month-dd で、日は必ず2桁（01 など）。月名は英語のフルスペル。
#include <bits/stdc++.h>
using namespace std;

const string MONTH[12] = {"January", "February", "March",     "April",   "May",      "June",
                          "July",    "August",   "September", "October", "November", "December"};

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int daysIn(int y, int m) {  // m は 0〜11
    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 1 && isLeap(y)) return 29;
    return d[m];
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string s;
        int k;
        cin >> s >> k;

        // "yyyy-month-dd" を3つに分ける
        int p1 = s.find('-');
        int p2 = s.rfind('-');
        int y = stoi(s.substr(0, p1));
        string name = s.substr(p1 + 1, p2 - p1 - 1);
        int d = stoi(s.substr(p2 + 1));
        int m = 0;
        for (int i = 0; i < 12; i++) {
            if (MONTH[i] == name) m = i;
        }

        for (int i = 0; i < k; i++) {
            d++;
            if (d > daysIn(y, m)) {
                d = 1;
                m++;
                if (m == 12) {
                    m = 0;
                    y++;
                }
            }
        }

        printf("Case %d: %d-%s-%02d\n", tc, y, MONTH[m].c_str(), d);
    }
    return 0;
}
