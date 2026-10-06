// CPE19 Odd Sum (UVa 10783)
// 考え方: a から b まで1つずつ見て、奇数だけ足す。範囲は最大 100 なのでこれで十分。
// 計算量: O(b - a) / ケース
// 注意: 出力は「Case 番号: 合計」。a と b は別々の行で来るが cin >> なら気にしなくてよい。
// 別解: 等差数列の和の公式で O(1) でも求められる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int i = a; i <= b; i++) {
            if (i % 2 == 1) sum += i;
        }
        cout << "Case " << c << ": " << sum << "\n";
    }

    return 0;
}
