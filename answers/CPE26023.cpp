// CPE26023 Scrolling Sign (UVa 11576)
// 考え方: 最初の単語は k 文字ぜんぶ流す。次の単語からは、「前の単語の末尾」と「次の単語の先頭」が
//         最大で何文字重なるかを調べ、重なった分は流さなくてよい。流す文字数 = k - 重なり。
// 計算量: O(w * k^2) / ケース（k, w ≤ 100 なので十分）
// 注意: 重なりは 0〜k 文字で、長い方から試して最初に合ったものを使う。
//       同じ単語が連続すると重なりが k になり、追加は 0 文字（「1回だけ見せればよい」と一致）。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k, w;
        cin >> k >> w;
        string prev;
        long long total = 0;
        for (int i = 0; i < w; i++) {
            string cur;
            cin >> cur;
            if (i == 0) {
                total += k;
            } else {
                int overlap = 0;
                for (int len = k; len >= 0; len--) {
                    // prev の末尾 len 文字 と cur の先頭 len 文字が同じか
                    if (prev.substr(k - len) == cur.substr(0, len)) {
                        overlap = len;
                        break;
                    }
                }
                total += k - overlap;
            }
            prev = cur;
        }
        cout << total << "\n";
    }
    return 0;
}
