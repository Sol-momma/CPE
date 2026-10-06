// CPE49-10 Summing Digits (UVa 11332)
// 考え方: 各桁の和 f(n) を求める操作を、n が1桁になるまで繰り返す。
//         桁の取り出しは % 10 と / 10（CPE49-03 と同じ）。
// 計算量: O(桁数) / 行（数回で1桁になる）
// 注意: 入力 0 は終わりの合図なので処理しない。
// 別解: 答えは n % 9（ただし 0 になるときは 9）で一発で求まる（数字根）。
#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long n) {
    long long s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n) {
        if (n == 0) break;
        while (n >= 10) n = digitSum(n);
        cout << n << "\n";
    }
    return 0;
}
