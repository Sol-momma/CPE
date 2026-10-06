// CPE26-043 Is it multiple of 3? (UVa 13178)
// 考え方: 3の倍数かどうかは「各桁の和が3の倍数か」で決まる。
//         12345678910... の各桁の和は、1+2+...+n の各数の桁和を足したもので、3で割った余りは
//         1+2+...+n = n(n+1)/2 を3で割った余りと同じ（各数の桁和 ≡ その数 (mod 3)）。
// 計算量: O(1) / ケース
// 注意: n は 10^9 まで。n(n+1)/2 は約 5×10^17 なので long long（int だと桁あふれ）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sum = n * (n + 1) / 2;  // 1 + 2 + ... + n
        cout << (sum % 3 == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
