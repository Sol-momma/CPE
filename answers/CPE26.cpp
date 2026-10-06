// CPE26 Fibonaccimal Base (UVa 948)
// 考え方: 1, 2, 3, 5, 8, ... のフィボナッチ数を用意し、大きい方から「引けるなら引いて 1、引けないなら 0」と貪欲に決める。
//         大きい方から貪欲に取ると、自動的に「連続する2つを同時に使わない」表現になる。
// 計算量: 1つの数あたり O(フィボナッチ数の個数) ≒ O(40)
// 注意: 先頭の 0 は出力しない（最初に 1 が立った位置から書く）。出力は "N = 表現 (fib)"。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> fib = {1, 2};
    while (fib.back() < 100000000) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long rest = n;
        string result = "";
        for (int i = (int)fib.size() - 1; i >= 0; i--) {
            if (fib[i] <= rest) {
                rest -= fib[i];
                result += '1';
            } else if (!result.empty()) {  // 先頭の 0 は付けない
                result += '0';
            }
        }

        cout << n << " = " << result << " (fib)\n";
    }

    return 0;
}
