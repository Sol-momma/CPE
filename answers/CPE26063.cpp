// CPE26063 Base -2 (UVa 11121)
// 考え方: 2 進数に直すときと同じく、n を -2 で割りながら下の桁から決める。
//         余りは 0 か 1 でなければならないので、余りが負になったら
//         余りに +2 して、商を 1 増やして帳尻を合わせる。
// 計算量: O(log |n|) / ケース
// 注意: C++ の % は負の数で余りが負になる（例: -3 % 2 = -1）ので、補正が必要。
//       n = 0 は桁が 1 つも作られないので、特別に "0" を出す。
//       出力は "Case #番号: 結果"。桁は下から作るので、最後に逆順にする。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        long long n;
        cin >> n;

        string s;
        if (n == 0) s = "0";
        while (n != 0) {
            long long r = n % 2;
            if (r < 0) r += 2;      // 余りを 0 か 1 にそろえる
            s += char('0' + r);
            n = (n - r) / (-2);     // r を引いてから -2 で割る（割り切れる）
        }
        reverse(s.begin(), s.end());

        cout << "Case #" << c << ": " << s << "\n";
    }
    return 0;
}
