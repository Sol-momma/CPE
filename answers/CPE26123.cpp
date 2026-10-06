// CPE26123 Lumberjack Sequencing (UVa 11942)
// 考え方: 10個の値が「小さい順」か「大きい順」のどちらかに全部そろっていれば Ordered。
//         隣り合う値を順に比べ、増えた回数と減った回数を数える。どちらかが0なら Ordered。
// 計算量: O(10) / 行
// 注意: 最初に "Lumberjacks:" の見出し行を1回だけ出す。
//       値は全部異なるので「等しい」ケースは考えなくてよい。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << "Lumberjacks:\n";
    while (n--) {
        int a[10];
        for (int i = 0; i < 10; i++) cin >> a[i];

        int up = 0, down = 0;
        for (int i = 1; i < 10; i++) {
            if (a[i] > a[i - 1]) up++;
            else down++;
        }

        if (up == 0 || down == 0) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
    return 0;
}
