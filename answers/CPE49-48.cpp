// CPE49-48 Cola (UVa 11150)
// 考え方: 空き瓶 3 本で 1 本もらえる交換を、空き瓶が 3 本未満になるまで繰り返す。
//         最後に空き瓶がちょうど 2 本残ったら、1 本借りて 3 本にすればもう 1 本飲める
//         （飲んだあとの空き瓶 1 本を返せばよい）。
// 計算量: 1ケース O(log N)
// 注意: 1 本しか残っていないときは 2 本借りる必要があり、返せないので不可。
// 別解: 答えは N * 3 / 2（整数の割り算）になる。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int total = n;  // 飲んだ本数
        int empty = n;  // 手元の空き瓶
        while (empty >= 3) {
            int got = empty / 3;
            total += got;
            empty = empty % 3 + got;
        }
        if (empty == 2) total++;

        cout << total << "\n";
    }

    return 0;
}
