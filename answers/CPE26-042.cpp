// CPE26-042 Primary Arithmetic (UVa 10035)
// 考え方: 筆算と同じく 1の位から順に、% 10 で桁を取り出して足す。
//         前の桁からの繰り上がり carry も足し、10 以上なら繰り上がり発生。
// 計算量: O(桁数) / 行
// 注意: 0回は "No carry operation."、1回は単数形 "operation"、2回以上は "operations"。
//       "999 1" のように繰り上がりが連鎖するケースで carry の足し忘れに注意。
#include <bits/stdc++.h>
using namespace std;

// a + b を筆算したときの繰り上がり回数を返す
int countCarries(long long a, long long b) {
    int count = 0;  // 繰り上がりの回数
    int carry = 0;  // 前の桁からの繰り上がり（0 か 1）

    while (a > 0 || b > 0) {
        int sum = a % 10 + b % 10 + carry;
        if (sum >= 10) {
            count++;
            carry = 1;
        } else {
            carry = 0;
        }
        a = a / 10;
        b = b / 10;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;  // 「0 0」は終わりの合図

        int c = countCarries(a, b);
        if (c == 0) {
            cout << "No carry operation.\n";
        } else if (c == 1) {
            cout << "1 carry operation.\n";
        } else {
            cout << c << " carry operations.\n";
        }
    }

    return 0;
}
