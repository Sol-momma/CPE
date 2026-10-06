// CPE49-32 Divide, But Not Quite Conquer! (UVa 10190)
// 考え方: n を m で割れる間ずっと割り、途中の数を記録する。最後に 1 になれば成功、ならなければ Boring!。
// 計算量: O(log n)
// 注意: n < 2 または m < 2 は必ず Boring!（m = 0 は割れない、m = 1 は永遠に終わらない、n = 0 / 1 は数列として不成立）。
//       途中で割り切れなくなった時点で Boring!。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    while (cin >> n >> m) {
        if (n < 2 || m < 2) {
            cout << "Boring!\n";
            continue;
        }

        vector<long long> seq;
        seq.push_back(n);
        while (n % m == 0) {
            n /= m;
            seq.push_back(n);
        }

        if (n != 1) {
            cout << "Boring!\n";
            continue;
        }

        for (int i = 0; i < (int)seq.size(); i++) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << "\n";
    }

    return 0;
}
