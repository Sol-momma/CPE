# CPE 試験対策プロジェクト

## 概要

CPE（Computer Programming Examination）の過去問49問を C++ で解くための学習リポジトリ。
問題はすべて UVa Online Judge の問題で、PDFをMarkdown変換済み。

**目標:** 全49問をC++で実装して試験に備える。
**レベル:** プログラミング初心者 → C++基礎から丁寧に説明する。

---

## ディレクトリ構造

```
index.html, assets/, data/   # 学習ページ（GitHub Pages）。49問とCPE26選集を1ページで切り替える
problems/                    # 問題文の画像（CPE49-01-1.png など）
cpe49/
  カテゴリフォルダ/            # 00_basics, 01_chars-and-strings, ...
    CPE49-xx 問題名/
      問題.pdf          # 元の問題PDF
      md/問題.md        # Markdown変換済み（こちらを読む）
      uva*.java         # 他者のJava参考解答（参考のみ、気にしなくてよい）
cpe26/                  # CPE26選集56問（CPE26-011_uva00272_TEX Quotes.pdf と md/）
answers/                # C++解答 CPE49-xx.cpp / CPE26-xxx.cpp、samples/ にサンプル
tests/                  # python3 tests/run.py CPE49-02
videos/                 # 解説動画 cpe49-xx.mp4（声＋効果音）。作成は problems.py、学習ページの「動画」タブが読む（対応表は assets/app.js の VIDEOS）
done/                   # 解き終わった問題を移す（任意）
```

**ID表記:** 49問は `CPE49-01`〜`CPE49-49`、CPE26選集は `CPE26-011`〜`CPE26-144`。名前（ディレクトリ・カテゴリ）は英語、見出しは English / 日本語 / 中文 の順。

**PDF読み方針:** PDFは直接読まず、同階層の `md/` 内のMarkdownを参照する。

---

## 問題一覧（全49問）

### 00_basics (CPE49-01〜CPE49-07)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-01 | Vito's Family | 10041 | `00_basics/CPE49-01 Vito'sFamily/md/10041.md` |
| CPE49-02 | Hashmat the Brave Warrior | 10055 | `00_basics/CPE49-02 Hashmat the Brave Warrior/md/10055.md` |
| CPE49-03 | Primary Arithmetic | 10035 | `00_basics/CPE49-03 Primary Arithmetic/md/10035.md` |
| CPE49-04 | The 3n+1 problem | 100 | `00_basics/CPE49-04 The 3n+1 problem/md/問題 100.md` |
| CPE49-05 | You can say 11 | 10929 | `00_basics/CPE49-05 You can say 11/md/10929.md` |
| CPE49-06 | Bangla Numbers | 10929 | `00_basics/CPE49-06 Bangla Numbers/md/10929.md` |
| CPE49-07 | List of Conquests | 10420 | `00_basics/CPE49-07 List of Conquests/md/10420.md` |

### 01_chars-and-strings — 文字と文字列 (CPE49-08〜CPE49-24)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-08 | What's Cryptanalysis | 10008 | `01_chars-and-strings/CPE49-08 What's Cryptanalysis/md/10008.md` |
| CPE49-09 | Decode the Mad man | 10222 | `01_chars-and-strings/CPE49-09 Decode the Mad man/md/10222.md` |
| CPE49-10 | Summing Digits | 11332 | `01_chars-and-strings/CPE49-10 Summing Digits/md/問題 11332.md` |
| CPE49-11 | Common Permutation | 10252 | `01_chars-and-strings/CPE49-11 Common Permutation/md/10252.md` |
| CPE49-12 | Rotating Sentences | 490 | `01_chars-and-strings/CPE49-12 Rotating Sentences/md/問題490.md` |
| CPE49-13 | (題名未設定) | 272 | `01_chars-and-strings/CPE49-13/md/問題 272.md` |
| CPE49-14 | Doom's Day Algorithm | 12019 | `01_chars-and-strings/CPE49-14 A - Doom's Day Algorithm/md/12019.md` |
| CPE49-15 | Jolly Jumpers | 10038 | `01_chars-and-strings/CPE49-15 Jolly Jumpers/md/10038.md` |
| CPE49-16 | What is the Probability!! | 10056 | `01_chars-and-strings/CPE49-16 What is the Probability!!/md/10056.md` |
| CPE49-17 | The Hotel with Infinite Rooms | 10170 | `01_chars-and-strings/CPE49-17 The Hotel with Infinite Rooms/md/問題 10170.md` |
| CPE49-18 | 498' | 10268 | `01_chars-and-strings/CPE49-18 498'/md/問題 10268.md` |
| CPE49-19 | Odd sum | 10783 | `01_chars-and-strings/CPE49-19 Odd sum/md/10783 (1).md` |
| CPE49-20 | Beat the Spread! | 10812 | `01_chars-and-strings/CPE49-20 Beat the Spread!/md/10812.md` |
| CPE49-21 | Symmetric Matrix | 11349 | `01_chars-and-strings/CPE49-21 Symmetric Matrix/md/11349.md` |
| CPE49-22 | Square Numbers | 11461 | `01_chars-and-strings/CPE49-22 Square Numbers/md/11461.md` |
| CPE49-23 | B2-Sequence | 11063 | `01_chars-and-strings/CPE49-23 B2-Sequence/md/11063.md` |
| CPE49-24 | Back to High School Physics | 10071 | `01_chars-and-strings/CPE49-24 Back to High School Physics/md/10071.md` |

### 02_number-bases — 進数変換 (CPE49-25〜CPE49-29)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-25 | (題名未設定) | 10093 | `02_number-bases/CPE49-25/md/10093.md` |
| CPE49-26 | (題名未設定) | 948 | `02_number-bases/CPE49-26/md/948.md` |
| CPE49-27 | Funny Encryption Method | 10019 | `02_number-bases/CPE49-27 Funny Encryption Method/md/10019.md` |
| CPE49-28 | Parity | 10931 | `02_number-bases/CPE49-28 Parity/md/10931.md` |
| CPE49-29 | Cheapest Base | 11005 | `02_number-bases/CPE49-29 Cheapest Base/md/問題 11005.md` |

### 03_primes-factors-multiples — 素数・因数・倍数 (CPE49-30〜CPE49-35)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-30 | Hartals | 10050 | `03_primes-factors-multiples/CPE49-30 Hartals/md/10050.md` |
| CPE49-31 | All You Need Is Love! | 10193 | `03_primes-factors-multiples/CPE49-31 All You Need Is Love!/md/10193.md` |
| CPE49-32 | Divide, But Not Quite Conquer! | 10190 | `03_primes-factors-multiples/CPE49-32 Divide, But Not Quite Conquer!/md/10190.md` |
| CPE49-33 | (題名未設定) | 10235 | `03_primes-factors-multiples/CPE49-33/md/10235.md` |
| CPE49-34 | (題名未設定) | 10922 | `03_primes-factors-multiples/CPE49-34/md/10922.md` |
| CPE49-35 | GCD | 11417 | `03_primes-factors-multiples/CPE49-35 GCD/md/11417.md` |

### 04_geometry-coordinates — 幾何・座標 (CPE49-36〜CPE49-39)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-36 | Largest Square | 10908 | `04_geometry-coordinates/CPE49-36 Largest Squrare/md/10908.md` |
| CPE49-37 | Satellites | 10221 | `04_geometry-coordinates/CPE49-37 Satellites/md/10221.md` |
| CPE49-38 | Can You Solve It | 10642 | `04_geometry-coordinates/CPE49-38 Can You Solve It/md/問題 10642.md` |
| CPE49-39 | Fourth Point !! | 10242 | `04_geometry-coordinates/CPE49-39 Fourth Point !!/md/10242.md` |

### 05_sorting-median — ソートと中央値 (CPE49-40〜CPE49-43)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-40 | A mid-summer night's dream | 10057 | `05_sorting-median/CPE49-40 A mid-summer night's dream/md/10057.md` |
| CPE49-41 | Tell me the frequencies! | 10062 | `05_sorting-median/CPE49-41 Tell me the frequencies!/md/10062.md` |
| CPE49-42 | Train Swapping | 299 | `05_sorting-median/CPE49-42 Train Swapping/md/問題299.md` |
| CPE49-43 | Hardwood Species | 10226 | `05_sorting-median/CPE49-43 Hardwood Species/md/10226.md` |

### 06_simulation — シミュレーション (CPE49-44〜CPE49-48)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-44 | Minesweeper | 10189 | `06_simulation/CPE49-44 Minesweeper/md/10189.md` |
| CPE49-45 | Die Game | 10409 | `06_simulation/CPE49-45 Die Game/md/10409.md` |
| CPE49-46 | Eb Alto Saxophone Player | 10415 | `06_simulation/CPE49-46 Eb Alto Saxophone Player/md/問題10415.md` |
| CPE49-47 | Mutant Flatworld Explorers | 118 | `06_simulation/CPE47Mutant Flatworld Explorers/md/Problem 118.md` |
| CPE49-48 | Cola | 11150 | `06_simulation/CPE49-48 Cola/md/11150.md` |

### その他 (CPE49-49)

| # | 問題名 | UVa# | MDファイル |
|---|--------|------|-----------|
| CPE49-49 | Sort! Sort!! and Sort!!! | 11321 | `CPE49-49 Sort! Sort!! and Sort!!!/md/問題 11321.md` |

---

## C++ 解答の進め方

### 基本テンプレート

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
g++-15 -o sol solution.cpp   # macOS の g++ は clang で bits/stdc++.h が動かないため g++-15 を使う
echo "入力" | ./sol
```

### 各問題の取り組み方

1. MDファイルで問題を読む
2. サンプル入力/出力を確認する
3. 解き方を考える（AIに相談してOK）
4. C++コードを書く
5. サンプルで動作確認

---

## 注意事項

- **MDのアーティファクト:** `(cid:2)` → `×`、`(cid:20)` → `≤` に読み替える（PDF変換の副作用）
- **Javaファイル:** 他者の参考解答。ロジックの参考にはできるが、そのまま流用しない
- **解答言語:** C++のみ（試験の要件）
