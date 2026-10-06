// CPE26-093 Digit Counting (UVa 1225)
// 考え方: 1〜N の各数について、% 10 で1桁ずつ取り出し、出てきた数字 0〜9 を数える。
// 計算量: O(N × 桁数)/ケース。N < 10000 なので十分速い。
// 注意: 出力は 0〜9 の個数を空白区切りで1行に。最後に余分な空白を付けない。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt[10] = {0};
        for (int i = 1; i <= n; i++) {
            int x = i;
            while (x > 0) {
                cnt[x % 10]++;
                x /= 10;
            }
        }
        for (int d = 0; d < 10; d++) {
            if (d > 0) cout << " ";
            cout << cnt[d];
        }
        cout << "\n";
    }
    return 0;
}
