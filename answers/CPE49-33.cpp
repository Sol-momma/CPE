// CPE49-33 Simply Emirp (UVa 10235)
// 考え方: N が素数か判定する。素数なら数字を逆順にした数も判定し、
//         「逆順も素数」かつ「逆順が N と違う数」なら emirp、そうでなければ prime。
// 計算量: O(√N)（1つの数あたり）
// 注意: 131 のような回文素数は逆順が自分と同じなので emirp ではなく prime。
//       素数判定は 2 〜 √N で割れるか調べる（i * i <= n の形で書くと sqrt の誤差がない）。
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverseNumber(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (!isPrime(n)) {
            cout << n << " is not prime.\n";
        } else {
            int r = reverseNumber(n);
            if (r != n && isPrime(r)) cout << n << " is emirp.\n";
            else cout << n << " is prime.\n";
        }
    }

    return 0;
}
