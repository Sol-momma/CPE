// CPE26084 Contest Scoreboard (UVa 10258)
// 考え方: 参加者ごとに「正解した問題数」と「ペナルティ時間」を記録する。
//         問題ごとに「すでに正解したか」と「それまでの不正解の回数」を持つ。
//           C: 初めての正解なら 解いた数 +1、ペナルティ += 提出時間 + 20 × 不正解回数
//           I: まだ正解していない問題なら不正解回数 +1
//           R, U, E: 得点に影響しない（ただし提出したことにはなる）
//         最後に「解いた数が多い → ペナルティが少ない → 番号が小さい」順に並べる。
// 計算量: O(提出数 + 100 log 100)
// 注意: 1回でも提出した参加者は、0問・0分でも一覧に出す（R や I だけの人も含む）。
//       正解した後の提出は無視する。不正解のペナルティは「正解より前の I」だけ。
//       入力は 空行 で区切られたケース。ケースの出力の間に空行を入れる。
#include <bits/stdc++.h>
using namespace std;

struct Team {
    int id;
    bool joined = false;
    int solved = 0;
    int penalty = 0;
    bool done[10] = {};
    int wrong[10] = {};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string line;
    getline(cin, line);
    t = stoi(line);

    for (int tc = 0; tc < t; tc++) {
        vector<Team> teams(101);
        for (int i = 0; i <= 100; i++) teams[i].id = i;

        // 空行を読み飛ばしてから、次の空行（か EOF）までがこのケース
        bool started = false;
        while (getline(cin, line)) {
            bool blank = line.find_first_not_of(" \t\r\n") == string::npos;
            if (blank) {
                if (started) break;
                continue;
            }
            started = true;

            istringstream iss(line);
            int c, p, time;
            char l;
            iss >> c >> p >> time >> l;

            Team& tm = teams[c];
            tm.joined = true;
            if (tm.done[p]) continue;  // 正解済みの問題への提出は無視
            if (l == 'C') {
                tm.done[p] = true;
                tm.solved++;
                tm.penalty += time + 20 * tm.wrong[p];
            } else if (l == 'I') {
                tm.wrong[p]++;
            }
        }

        vector<Team> list;
        for (int i = 1; i <= 100; i++) {
            if (teams[i].joined) list.push_back(teams[i]);
        }
        sort(list.begin(), list.end(), [](const Team& a, const Team& b) {
            if (a.solved != b.solved) return a.solved > b.solved;
            if (a.penalty != b.penalty) return a.penalty < b.penalty;
            return a.id < b.id;
        });

        if (tc > 0) cout << "\n";
        for (auto& tm : list) cout << tm.id << " " << tm.solved << " " << tm.penalty << "\n";
    }
    return 0;
}
