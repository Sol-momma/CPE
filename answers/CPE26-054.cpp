// CPE26-054 Prime Land (UVa 516)
// 考え方: 各行の「素数 指数」の組から x = p1^e1 × p2^e2 × ... を計算し、x - 1 を作る。
//         x - 1 を 2, 3, 4, ... で割って素因数分解し、大きい素数から順に「素数 指数」を出力する。
// 計算量: O(√x) / 行（x ≤ 32767）
// 注意: 行末の改行まで 1 行ずつ読む（getline）。最初の数が 0 なら入力の終わり。
//       出力は素数の降順で、指数が 0 の素数は出さない。行末に余計な空白を付けない。
#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int p, e;
        if (!(ss >> p)) continue;  // 空行は読み飛ばす
        if (p == 0) break;
        ss >> e;

        // x を作る
        long long x = 1;
        do {
            for (int i = 0; i < e; i++) x *= p;
        } while (ss >> p >> e);

        // x - 1 を素因数分解（小さい素数から）
        int m = x - 1;
        vector<pair<int, int>> factors;  // (素数, 指数)
        for (int q = 2; q * q <= m; q++) {
            if (m % q == 0) {
                int cnt = 0;
                while (m % q == 0) {
                    m /= q;
                    cnt++;
                }
                factors.push_back({q, cnt});
            }
        }
        if (m > 1) factors.push_back({m, 1});

        // 大きい素数から出力
        for (int i = (int)factors.size() - 1; i >= 0; i--) {
            if (i != (int)factors.size() - 1) cout << " ";
            cout << factors[i].first << " " << factors[i].second;
        }
        cout << "\n";
    }
    return 0;
}
