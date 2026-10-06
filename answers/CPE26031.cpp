// CPE26031 Mirror Clock (UVa 11650)
// 考え方: 鏡に映した時計は、12:00 から見た針の位置が左右反転する。
//         だから本当の時刻 = 12:00 - 鏡の時刻。分に直して 720（12時間）から引く。
// 計算量: O(1) / 行
// 注意: 12時は 0時間として扱い、答えが 0 時台になるときは 12 に直す（12:00 → 12:00）。
//       出力は 01:51 のように 2桁ずつゼロ埋めする。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int h, m;
        scanf("%d:%d", &h, &m);

        int total = (h % 12) * 60 + m;      // 12時間制の分
        int real = (720 - total) % 720;     // 鏡の反対側の時刻（分）
        int rh = real / 60;
        int rm = real % 60;
        if (rh == 0) rh = 12;               // 0時台は12時台と表す

        printf("%02d:%02d\n", rh, rm);
    }
    return 0;
}
