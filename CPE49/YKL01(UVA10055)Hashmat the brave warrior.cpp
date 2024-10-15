#include <iostream>
using namespace std;

int main() {
    long long a, b;
    
    // 入力が終わるまでループ
    while (cin >> a >> b) {
        cout << abs(a - b) << endl;  // 差を計算して出力
    }
    
    return 0;
}

// 理解できた◎


// long long 型をなぜつかうのか？
// めちゃめちゃ大きな整数だから
// この型はめちゃくちゃ大きい整数を格納するために使う。問題文には、兵士の数が２＾３２に達すると記述されていることから必要とされていて、通常のint型だと足りないから。

// なぜforループではなくてwhile ループを使うのか？
// 繰り返し回数が不明だから。
// この問題は、何回ループが回るか（入力が何行あるか）が事前には分からないためです。入力はファイルの終わり（EOF）まで続くので、繰り返し回数が決まっていないのです。
// 入力が終わるまで繰り返す必要があるため、while ループを使っている。for ループだと、入力が終わるまで繰り返すことができない。

// abs() 関数を使って a と b の絶対差を計算する