# CPE 試験対策

CPE（Collegiate Programming Examination）台湾の大学生向けプログラミング試験の過去問対策リポジトリ。

UVa Online Judge の問題を C++ で解くことを目標にしています。

---

## フォルダ構成

```
.
├── 49題/          # 過去問49問（カテゴリ別）
│   ├── 00_基礎/
│   ├── 01_字元與字串/    （文字と文字列）
│   ├── 02_進位制轉換/    （進数変換）
│   ├── 03_質數、因數與倍數/ （素数・因数・倍数）
│   ├── 04_幾何與座標/    （幾何・座標）
│   ├── 05_排序與中位數/  （ソートと中央値）
│   └── 06_模擬/          （シミュレーション）
│
└── done/          # 解き終わった問題（別の方の参考解答）
    ├── CPE 1星/   （難易度1）
    ├── CPE 2 星/  （難易度2）
    ├── CPE 3 星/  （難易度3）
    └── CPE 4星/   （難易度4）
```

各問題フォルダの中身：

```
CPExx 問題名/
  ├── 問題.pdf        # 元の問題PDF
  ├── md/問題.md      # Markdown変換済み（AIで読みやすい形式）
  └── uva*.java       # 参考解答（Java）
```

---

## 問題一覧（全49問）

| # | カテゴリ | 問題名 | UVa# |
|---|----------|--------|------|
| CPE01 | 基礎 | Vito's Family | 10041 |
| CPE02 | 基礎 | Hashmat the Brave Warrior | 10055 |
| CPE03 | 基礎 | Primary Arithmetic | 10035 |
| CPE04 | 基礎 | The 3n+1 problem | 100 |
| CPE05 | 基礎 | You can say 11 | 10929 |
| CPE06 | 基礎 | Bangla Numbers | 10929 |
| CPE07 | 基礎 | List of Conquests | 10420 |
| CPE08 | 文字列 | What's Cryptanalysis | 10008 |
| CPE09 | 文字列 | Decode the Mad man | 10222 |
| CPE10 | 文字列 | Summing Digits | 11332 |
| CPE11 | 文字列 | Common Permutation | 10252 |
| CPE12 | 文字列 | Rotating Sentences | 490 |
| CPE13 | 文字列 | TeX Quotes | 272 |
| CPE14 | 文字列 | Doom's Day Algorithm | 12019 |
| CPE15 | 文字列 | Jolly Jumpers | 10038 |
| CPE16 | 文字列 | What is the Probability!! | 10056 |
| CPE17 | 文字列 | The Hotel with Infinite Rooms | 10170 |
| CPE18 | 文字列 | 498' | 10268 |
| CPE19 | 文字列 | Odd sum | 10783 |
| CPE20 | 文字列 | Beat the Spread! | 10812 |
| CPE21 | 文字列 | Symmetric Matrix | 11349 |
| CPE22 | 文字列 | Square Numbers | 11461 |
| CPE23 | 文字列 | B2-Sequence | 11063 |
| CPE24 | 文字列 | Back to High School Physics | 10071 |
| CPE25 | 進数変換 | An Easy Problem! | 10093 |
| CPE26 | 進数変換 | Fibonaccimal Base | 948 |
| CPE27 | 進数変換 | Funny Encryption Method | 10019 |
| CPE28 | 進数変換 | Parity | 10931 |
| CPE29 | 進数変換 | Cheapest Base | 11005 |
| CPE30 | 素数 | Hartals | 10050 |
| CPE31 | 素数 | All You Need Is Love! | 10193 |
| CPE32 | 素数 | Divide, But Not Quite Conquer! | 10190 |
| CPE33 | 素数 | Simply Emirp | 10235 |
| CPE34 | 素数 | 2 the 9s | 10922 |
| CPE35 | 素数 | GCD | 11417 |
| CPE36 | 幾何 | Largest Square | 10908 |
| CPE37 | 幾何 | Satellites | 10221 |
| CPE38 | 幾何 | Can You Solve It | 10642 |
| CPE39 | 幾何 | Fourth Point !! | 10242 |
| CPE40 | ソート | A mid-summer night's dream | 10057 |
| CPE41 | ソート | Tell me the frequencies! | 10062 |
| CPE42 | ソート | Train Swapping | 299 |
| CPE43 | ソート | Hardwood Species | 10226 |
| CPE44 | シミュレーション | Minesweeper | 10189 |
| CPE45 | シミュレーション | Die Game | 10409 |
| CPE46 | シミュレーション | Eb Alto Saxophone Player | 10415 |
| CPE47 | シミュレーション | Mutant Flatworld Explorers | 118 |
| CPE48 | シミュレーション | Cola | 11150 |
| CPE49 | ソート | Sort! Sort!! and Sort!!! | 11321 |

---

## 解答方針

- 解答言語: **C++**
- 提出先: [UVa Online Judge](https://onlinejudge.org/)

### C++ 基本テンプレート

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ここに解答を書く

    return 0;
}
```

### コンパイルと実行

```bash
g++ -o sol solution.cpp
echo "入力データ" | ./sol
```
