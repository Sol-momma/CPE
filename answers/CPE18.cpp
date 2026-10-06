// CPE18 498-bis (UVa 10268)
// 考え方: 係数 a0..an は「次数の高い順」。a_i の項は x^(n-i) で、微分すると (n-i) * a_i * x^(n-i-1)。
//         ホーナー法で ans = ans * x + a_i * (n-i) を i = 0..n-1 で繰り返す。
// 計算量: O(n) / ケース
// 注意: 係数の個数は行ごとに違うので getline で1行読んで分解する。
//       途中計算は long long。係数が1個（定数）なら答えは 0。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string xLine, coefLine;
    while (getline(cin, xLine) && getline(cin, coefLine)) {
        long long x = stoll(xLine);

        vector<long long> a;
        stringstream ss(coefLine);
        long long v;
        while (ss >> v) a.push_back(v);

        int n = (int)a.size() - 1;  // 多項式の次数
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans * x + a[i] * (n - i);
        }
        cout << ans << "\n";
    }

    return 0;
}
