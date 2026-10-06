// CPE22 Square Numbers (UVa 11461)
// 考え方: 1, 4, 9, 16, ... と i*i を順に作り、a 以上 b 以下のものを数える。
//         b ≤ 100000 なので i は最大 316 程度で、ループで十分速い。
// 計算量: O(√b) / 行
// 注意: a と b は両端を含む（inclusive）。「0 0」で終了し、その行は処理しない。
// 別解: floor(√b) - floor(√(a-1)) で O(1)。ただし sqrt の誤差に注意。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        int count = 0;
        for (int i = 1; i * i <= b; i++) {
            if (i * i >= a) count++;
        }
        cout << count << "\n";
    }

    return 0;
}
