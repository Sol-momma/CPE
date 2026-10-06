// CPE27 Funny Encryption Method (UVa 10019)
// 考え方: b1 = M を10進数として2進数にしたときの 1 の個数。
//         b2 = M を16進数として読んだときの 1 の個数。16進数は1桁がちょうど2進4桁に対応するので、
//              10進表記の各桁 d（0〜9）について「d の 1 の個数」を足せばよい。
// 計算量: O(桁数)
// 注意: 出力は b1 と b2 だけ（暗号化の結果は出さない）。
#include <bits/stdc++.h>
using namespace std;

int countOnes(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;

        int b1 = countOnes(m);

        int b2 = 0;
        int x = m;
        while (x > 0) {
            b2 += countOnes(x % 10);  // 10進の1桁 = 16進の1桁
            x /= 10;
        }

        cout << b1 << " " << b2 << "\n";
    }

    return 0;
}
