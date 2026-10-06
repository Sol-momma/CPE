// CPE49-17 The Hotel with Infinite Rooms (UVa 10170)
// 考え方: S人, S+1人, ..., n人 のグループが泊まり終わるまでの日数は S + (S+1) + ... + n。
//         この合計が D 以上になる最小の n が答え。
//         D は最大 10^15 なので1グループずつ足すと遅い。n を二分探索する。
// 計算量: O(log D) / 行
// 注意: すべて long long で計算する。
// 別解: 2次方程式の解の公式で n を求め、誤差を ±1 で調整してもよい。
#include <bits/stdc++.h>
using namespace std;

// S 人から n 人までのグループが泊まる日数の合計
long long totalDays(long long s, long long n) {
    return (n * (n + 1) - s * (s - 1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long s, d;
    while (cin >> s >> d) {
        long long lo = s, hi = 100000000;  // 答えは必ず [lo, hi] にある
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (totalDays(s, mid) >= d) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }

    return 0;
}
