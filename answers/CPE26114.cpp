// CPE26114 Generating Fast, Sorted Permutation (UVa 10098)
// 考え方: 文字列を昇順に並べ替えてから next_permutation を繰り返すと、
//         辞書順に全順列が出る。同じ文字があっても重複せずに出力される。
// 計算量: O(出力する順列の数 × 長さ)
// 注意: 大文字・小文字は別の文字（ASCII順: 数字 < 大文字 < 小文字）。sort の標準順でよい。
//       各出力グループのあとに空行を1つ出す（最後のグループの後ろにも）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());  // 最小の順列から始める

        do {
            cout << s << "\n";
        } while (next_permutation(s.begin(), s.end()));
        cout << "\n";  // グループのあとの空行
    }
    return 0;
}
