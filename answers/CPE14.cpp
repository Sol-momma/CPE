// CPE14 Doom's Day Algorithm (UVa 12019)
// 考え方: 2011年1月1日は土曜日。1月1日から何日後かを数え、7で割った余りで曜日を決める。
//         2011年はうるう年ではないので、2月は28日。
// 計算量: O(12) / ケース
// 注意: 曜日の配列は「土曜日」から始める（余り0 = 1月1日 = 土曜日）。
// 別解: 問題文どおり doomsday（4/4, 6/6 など）からの差で求めてもよい。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string names[7] = {"Saturday", "Sunday", "Monday", "Tuesday",
                       "Wednesday", "Thursday", "Friday"};

    int t;
    cin >> t;
    while (t--) {
        int m, d;
        cin >> m >> d;
        int offset = d - 1;  // 1月1日から何日後か
        for (int i = 1; i < m; i++) offset += daysInMonth[i];
        cout << names[offset % 7] << "\n";
    }

    return 0;
}
