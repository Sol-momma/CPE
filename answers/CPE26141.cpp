// CPE26141 Throwing cards away I (UVa 10935)
// 考え方: カードを queue に 1〜n の順で入れ、問題文どおりに動かす。
//         「先頭を捨てる → 次の先頭を取り出して末尾に回す」を、残り1枚になるまで繰り返す。
// 計算量: O(n) / ケース
// 注意: n=1 のときは捨てるカードが無いので "Discarded cards:" だけを出す（後ろに空白も付けない）。
//       カード番号は ", " 区切り。最後に余ったカードを "Remaining card: x" で出す。0 で入力終了。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);

        cout << "Discarded cards:";
        bool first = true;
        while (q.size() >= 2) {
            int top = q.front();  // 先頭を捨てる
            q.pop();
            cout << (first ? " " : ", ") << top;
            first = false;

            q.push(q.front());  // 次の先頭を末尾へ
            q.pop();
        }
        cout << "\n";
        cout << "Remaining card: " << q.front() << "\n";
    }
    return 0;
}
