// CPE26-142 Rockabye Tobby (UVa 13190)
// 考え方: 薬 i は 時刻 f, 2f, 3f, ... に飲む。全部の時刻を作ると多すぎるので、
//         priority_queue に「次に飲む時刻」だけを薬ごとに1つずつ入れておき、
//         一番早いものを取り出す → その薬の次の時刻 (t + f) を入れ直す、を k 回繰り返す。
// 計算量: O(k log n) / ケース
// 注意: 同じ時刻なら優先度（入力で先に出てきた薬）が先。キーを (時刻, 入力順) にすれば自然にそうなる。
//       priority_queue は大きい順に出すので、greater を使って小さい順にする。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<string> name(n);
        vector<int> freq(n);
        // (次に飲む時刻, 入力順) を小さい順に取り出す
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            cin >> name[i] >> freq[i];
            pq.push({freq[i], i});
        }

        for (int c = 0; c < k; c++) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int t = cur.first;
            int i = cur.second;
            cout << t << " " << name[i] << "\n";
            pq.push({t + freq[i], i});
        }
    }
    return 0;
}
