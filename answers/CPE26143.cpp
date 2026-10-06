// CPE26143 Parentheses Balance (UVa 673)
// 考え方: stack を使う。開き括弧 ( [ は積み、閉じ括弧 ) ] が来たら
//         スタックの一番上が対応する開き括弧か確かめて取り除く。
//         最後にスタックが空なら正しい。
// 計算量: O(文字数)
// 注意: 閉じ括弧が来たのにスタックが空、または種類が違えば即 No。
//       最後にスタックが残っていても No（例 "(("）。空文字列は正しい（Yes）なので空行にも対応する。
//       n を読んだあとの改行を読み捨ててから getline する。
#include <bits/stdc++.h>
using namespace std;

bool balanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == ']') {
            char open = (c == ')') ? '(' : '[';
            if (st.empty() || st.top() != open) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string line;
    getline(cin, line);  // n の後ろの改行を読み捨てる

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        cout << (balanced(line) ? "Yes" : "No") << "\n";
    }
    return 0;
}
