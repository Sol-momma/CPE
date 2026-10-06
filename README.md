# CPE 試験対策

CPE（Collegiate Programming Examination）台湾の大学生向けプログラミング試験の過去問対策リポジトリ。

UVa Online Judge の問題を C++ で解くことを目標にしています。

## ブラウザで見る

- **学習ページ（1ページ）**: https://sol-momma.github.io/CPE/
  - 上部のタブで **CPE 49** と **CPE26選集** を切り替え。見出しは English / 日本語 / 中文 の順。
  - **Problems**: 問題画像・単語・日本語訳・サンプル・解答コード。検索・型/難しさ/未解決での絞り込み・前へ/次へ（`←` `→` / `j` `k`）・解いた印（この端末のブラウザに保存）。
  - **PDFs**: 元の問題PDFの一覧。
  - **Patterns**: 解く前の5つの質問・8つの型・簡単な順。
- URL は `#/<set>/<tab>/<ID>`（例: `#/26/problems/CPE26-044`）で、そのまま共有できます。

---

## フォルダ構成

```
.
├── index.html         # 学習ページ本体（GitHub Pages のトップ）
├── assets/            # app.css / app.js（共通のCSS・JS）
├── data/              # cpe49.js / cpe26.js（問題データ）, types.js（8つの型）
├── problems/          # 問題文のPDFを画像にしたもの（CPE49-01-1.png など）
│
├── cpe49/             # 過去問49問（カテゴリ別）  ID: CPE49-01〜CPE49-49
│   ├── 00_basics/                      （基礎）
│   ├── 01_chars-and-strings/           （文字と文字列）
│   ├── 02_number-bases/                （進数変換）
│   ├── 03_primes-factors-multiples/    （素数・因数・倍数）
│   ├── 04_geometry-coordinates/        （幾何・座標）
│   ├── 05_sorting-median/              （ソートと中央値）
│   └── 06_simulation/                  （シミュレーション）
├── cpe26/             # CPE26選集56問のPDFと md/   ID: CPE26-011〜CPE26-144
│
├── answers/           # C++ 解答（CPE49-01.cpp〜CPE49-49.cpp, CPE26-011.cpp〜CPE26-144.cpp）
│   └── samples/       # サンプル入出力（CPE49-01.in / .out など）
├── tests/             # テストランナー（python3 tests/run.py CPE49-02）
├── cpp基礎/           # C++ の基礎練習
│
└── done/              # 解き終わった問題（別の方の参考解答）
    ├── CPE 1星/   （難易度1）
    ├── CPE 2 星/  （難易度2）
    ├── CPE 3 星/  （難易度3）
    └── CPE 4星/   （難易度4）
```

各問題フォルダ（`cpe49/`）の中身：

```
CPE49-xx 問題名/
  ├── 問題.pdf        # 元の問題PDF
  ├── md/問題.md      # Markdown変換済み（AIで読みやすい形式）
  └── uva*.java       # 参考解答（Java）
```

CPE26選集の出典: https://cpe.mcu.edu.tw/cpelist.php

---

## 問題一覧（全49問）

| # | カテゴリ | 問題名 | UVa# |
|---|----------|--------|------|
| CPE49-01 | 基礎 | [Vito's Family](cpe49/00_basics/CPE49-01%20Vito'sFamily/Vito'sFamily.pdf) | 10041 |
| CPE49-02 | 基礎 | [Hashmat the Brave Warrior](cpe49/00_basics/CPE49-02%20Hashmat%20the%20Brave%20Warrior/Hashmat%20the%20Brave%20Warrior.pdf) | 10055 |
| CPE49-03 | 基礎 | [Primary Arithmetic](cpe49/00_basics/CPE49-03%20Primary%20Arithmetic/Primary%20Arithmetic.pdf) | 10035 |
| CPE49-04 | 基礎 | [The 3n+1 problem](cpe49/00_basics/CPE49-04%20The%203n%2B1%20problem/The%203n%2B1%20problem.pdf) | 100 |
| CPE49-05 | 基礎 | [You can say 11](cpe49/00_basics/CPE49-05%20You%20can%20say%2011/You%20can%20say%2011.pdf) | 10929 |
| CPE49-06 | 基礎 | [Bangla Numbers](cpe49/00_basics/CPE49-06%20Bangla%20Numbers/Bangla%20Numbers.pdf) | 10929 |
| CPE49-07 | 基礎 | [List of Conquests](cpe49/00_basics/CPE49-07%20List%20of%20Conquests/List%20of%20Conquests.pdf) | 10420 |
| CPE49-08 | 文字列 | [What's Cryptanalysis](cpe49/01_chars-and-strings/CPE49-08%20What's%20Cryptanalysis/What's%20Cryptanalysis.pdf) | 10008 |
| CPE49-09 | 文字列 | [Decode the Mad man](cpe49/01_chars-and-strings/CPE49-09%20Decode%20the%20Mad%20man/Decode%20the%20Mad%20man.pdf) | 10222 |
| CPE49-10 | 文字列 | [Summing Digits](cpe49/01_chars-and-strings/CPE49-10%20Summing%20Digits/Summing%20Digits.pdf) | 11332 |
| CPE49-11 | 文字列 | [Common Permutation](cpe49/01_chars-and-strings/CPE49-11%20Common%20Permutation/Common%20Permutation.pdf) | 10252 |
| CPE49-12 | 文字列 | [Rotating Sentences](cpe49/01_chars-and-strings/CPE49-12%20Rotating%20Sentences/Rotating%20Sentences.pdf) | 490 |
| CPE49-13 | 文字列 | [TeX Quotes](cpe49/01_chars-and-strings/CPE49-13/%E5%95%8F%E9%A1%8C%20272.pdf) | 272 |
| CPE49-14 | 文字列 | [Doom's Day Algorithm](cpe49/01_chars-and-strings/CPE49-14%20A%20-%20Doom's%20Day%20Algorithm/A%20-%20Doom's%20Day%20Algorithm.pdf) | 12019 |
| CPE49-15 | 文字列 | [Jolly Jumpers](cpe49/01_chars-and-strings/CPE49-15%20Jolly%20Jumpers/Jolly%20Jumpers.pdf) | 10038 |
| CPE49-16 | 文字列 | [What is the Probability!!](cpe49/01_chars-and-strings/CPE49-16%20What%20is%20the%20Probability!!/What%20is%20the%20Probability!!.pdf) | 10056 |
| CPE49-17 | 文字列 | [The Hotel with Infinite Rooms](cpe49/01_chars-and-strings/CPE49-17%20The%20Hotel%20with%20Infinite%20Rooms/The%20Hotel%20with%20Infinite%20Rooms.pdf) | 10170 |
| CPE49-18 | 文字列 | [498'](cpe49/01_chars-and-strings/CPE49-18%20498'/498'.pdf) | 10268 |
| CPE49-19 | 文字列 | [Odd sum](cpe49/01_chars-and-strings/CPE49-19%20Odd%20sum/Odd%20sum.pdf) | 10783 |
| CPE49-20 | 文字列 | [Beat the Spread!](cpe49/01_chars-and-strings/CPE49-20%20Beat%20the%20Spread!/Beat%20the%20Spread!.pdf) | 10812 |
| CPE49-21 | 文字列 | [Symmetric Matrix](cpe49/01_chars-and-strings/CPE49-21%20Symmetric%20Matrix/Symmetric%20Matrix.pdf) | 11349 |
| CPE49-22 | 文字列 | [Square Numbers](cpe49/01_chars-and-strings/CPE49-22%20Square%20Numbers/Square%20Numbers.pdf) | 11461 |
| CPE49-23 | 文字列 | [B2-Sequence](cpe49/01_chars-and-strings/CPE49-23%20B2-Sequence/B2-Sequence.pdf) | 11063 |
| CPE49-24 | 文字列 | [Back to High School Physics](cpe49/01_chars-and-strings/CPE49-24%20Back%20to%20High%20School%20Physics/Back%20to%20High%20School%20Physics.pdf) | 10071 |
| CPE49-25 | 進数変換 | [An Easy Problem!](cpe49/02_number-bases/CPE49-25/10093.pdf) | 10093 |
| CPE49-26 | 進数変換 | [Fibonaccimal Base](cpe49/02_number-bases/CPE49-26/948.pdf) | 948 |
| CPE49-27 | 進数変換 | [Funny Encryption Method](cpe49/02_number-bases/CPE49-27%20Funny%20Encryption%20Method/Funny%20Encryption%20Method.pdf) | 10019 |
| CPE49-28 | 進数変換 | [Parity](cpe49/02_number-bases/CPE49-28%20Parity/Parity.pdf) | 10931 |
| CPE49-29 | 進数変換 | [Cheapest Base](cpe49/02_number-bases/CPE49-29%20Cheapest%20Base/Cheapest%20Base.pdf) | 11005 |
| CPE49-30 | 素数 | [Hartals](cpe49/03_primes-factors-multiples/CPE49-30%20Hartals/Hartals.pdf) | 10050 |
| CPE49-31 | 素数 | [All You Need Is Love!](cpe49/03_primes-factors-multiples/CPE49-31%20All%20You%20Need%20Is%20Love!/All%20You%20Need%20Is%20Love!.pdf) | 10193 |
| CPE49-32 | 素数 | [Divide, But Not Quite Conquer!](cpe49/03_primes-factors-multiples/CPE49-32%20Divide,%20But%20Not%20Quite%20Conquer!/Divide,%20But%20Not%20Quite%20Conquer!.pdf) | 10190 |
| CPE49-33 | 素数 | [Simply Emirp](cpe49/03_primes-factors-multiples/CPE49-33/10235.pdf) | 10235 |
| CPE49-34 | 素数 | [2 the 9s](cpe49/03_primes-factors-multiples/CPE49-34/10922.pdf) | 10922 |
| CPE49-35 | 素数 | [GCD](cpe49/03_primes-factors-multiples/CPE49-35%20GCD/GCD.pdf) | 11417 |
| CPE49-36 | 幾何 | [Largest Square](cpe49/04_geometry-coordinates/CPE49-36%20Largest%20Squrare/Largest%20Squrare.pdf) | 10908 |
| CPE49-37 | 幾何 | [Satellites](cpe49/04_geometry-coordinates/CPE49-37%20Satellites/Satellites.pdf) | 10221 |
| CPE49-38 | 幾何 | [Can You Solve It](cpe49/04_geometry-coordinates/CPE49-38%20Can%20You%20Solve%20It/Can%20You%20Solve%20It.pdf) | 10642 |
| CPE49-39 | 幾何 | [Fourth Point !!](cpe49/04_geometry-coordinates/CPE49-39%20Fourth%20Point%20!!/Fourth%20Point%20!!.pdf) | 10242 |
| CPE49-40 | ソート | [A mid-summer night's dream](cpe49/05_sorting-median/CPE49-40%20A%20mid-summer%20night's%20dream/A%20mid-summer%20night's%20dream.pdf) | 10057 |
| CPE49-41 | ソート | [Tell me the frequencies!](cpe49/05_sorting-median/CPE49-41%20Tell%20me%20the%20frequencies!/Tell%20me%20the%20frequencies!.pdf) | 10062 |
| CPE49-42 | ソート | [Train Swapping](cpe49/05_sorting-median/CPE49-42%20Train%20Swapping/Train%20Swapping.pdf) | 299 |
| CPE49-43 | ソート | [Hardwood Species](cpe49/05_sorting-median/CPE49-43%20Hardwood%20Species/Hardwood%20Species.pdf) | 10226 |
| CPE49-44 | シミュレーション | [Minesweeper](cpe49/06_simulation/CPE49-44%20Minesweeper/Minesweeper.pdf) | 10189 |
| CPE49-45 | シミュレーション | [Die Game](cpe49/06_simulation/CPE49-45%20Die%20Game/Die%20Game.pdf) | 10409 |
| CPE49-46 | シミュレーション | [Eb Alto Saxophone Player](cpe49/06_simulation/CPE49-46%20Eb%20Alto%20Saxophone%20Player/Eb%20Alto%20Saxophone%20Player.pdf) | 10415 |
| CPE49-47 | シミュレーション | [Mutant Flatworld Explorers](cpe49/06_simulation/CPE47Mutant%20Flatworld%20Explorers/Mutant%20Flatworld%20Explorers.pdf) | 118 |
| CPE49-48 | シミュレーション | [Cola](cpe49/06_simulation/CPE49-48%20Cola/Cola.pdf) | 11150 |
| CPE49-49 | ソート | [Sort! Sort!! and Sort!!!](cpe49/CPE49-49%20Sort!%20Sort!!%20and%20Sort!!!/Sort!%20Sort!!%20and%20Sort!!!.pdf) | 11321 |

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
g++-15 -o sol solution.cpp   # macOS の g++ は clang で bits/stdc++.h が使えないため g++-15
echo "入力データ" | ./sol
```

### テスト

```bash
python3 tests/run.py CPE49-02          # サンプル + エッジケース + ランダム入力
```
