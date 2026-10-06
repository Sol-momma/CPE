// CPE26062 The Base-1 Number System (UVa 11398)
// 考え方: 空白区切りの「0 の塊」を1つずつ読む。長さ 1 なら flag = 1、長さ 2 なら flag = 0、
//         長さ n > 2 なら flag の値を (n - 2) 個 2 進数の末尾に付ける。
//         付けるたびに value = value * 2 + flag とすれば、2 進数がそのまま 10 進数の値になる。
// 計算量: O(入力の長さ)
// 注意: 1 つの数は複数行にまたがってよく、'#' で 1 件終わり、'~' で入力全体が終わる。
//       行ではなく空白区切りの単語で読む。最終的な値は最大 30 桁なので long long で安全。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string token;
    long long value = 0;
    int flag = 0;
    while (cin >> token) {
        if (token == "~") break;
        if (token == "#") {
            cout << value << "\n";
            value = 0;  // 次のケースに備えて初期化
            flag = 0;
            continue;
        }

        int len = token.size();  // 0 の個数
        if (len == 1) {
            flag = 1;
        } else if (len == 2) {
            flag = 0;
        } else {
            for (int i = 0; i < len - 2; i++) value = value * 2 + flag;
        }
    }
    return 0;
}
