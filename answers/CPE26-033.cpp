// CPE26-033 How old are you? (UVa 11219)
// 考え方: 年の差を取り、今年まだ誕生日が来ていなければ 1 引く。
//         誕生日が今日より未来なら "Invalid birth date"、年齢が 130 を超えたら "Check birth date"。
// 計算量: O(1) / ケース
// 注意: 日付は DD/MM/YYYY の順（日が先）。ケースの前に空行があるが scanf は空白を読み飛ばす。
//       「誕生日が未来か」は (年, 月, 日) の順に比べる。年齢ちょうど 130 は有効。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int no = 1; no <= t; no++) {
        int cd, cm, cy, bd, bm, by;
        scanf("%d/%d/%d", &cd, &cm, &cy);  // 今日
        scanf("%d/%d/%d", &bd, &bm, &by);  // 誕生日

        printf("Case #%d: ", no);
        // (年, 月, 日) を1つの数にして大小を比べる
        long long today = cy * 10000LL + cm * 100 + cd;
        long long birth = by * 10000LL + bm * 100 + bd;
        if (birth > today) {
            printf("Invalid birth date\n");
        } else {
            int age = cy - by;
            if (cm * 100 + cd < bm * 100 + bd) age--;  // 今年の誕生日がまだ
            if (age > 130) {
                printf("Check birth date\n");
            } else {
                printf("%d\n", age);
            }
        }
    }
    return 0;
}
