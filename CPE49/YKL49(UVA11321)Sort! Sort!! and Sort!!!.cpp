#include <iostream>
#include <vector>
#include <algorithm>  // sort() 関数を使うため
using namespace std;

// カスタムソート関数
bool customSort(int a, int b, int M) {
    int modA = a % M;
    int modB = b % M;
    
    // まず剰余値で比較
    if (modA != modB) return modA < modB;
    
    // 剰余値が同じなら奇数と偶数の順序を考慮
    bool isOddA = a % 2 != 0;
    bool isOddB = b % 2 != 0;
    
    if (isOddA && !isOddB) return true;  // 奇数が先
    if (!isOddA && isOddB) return false; // 偶数が後
    
    // 両方奇数なら大きい方を先に
    if (isOddA && isOddB) return a > b;
    
    // 両方偶数なら小さい方を先に
    return a < b;
}

int main() {
    int N, M;
    
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;  // 0 0 が来たら終了
        
        vector<int> numbers(N);
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }
        
        // カスタムソートを適用
        sort(numbers.begin(), numbers.end(), [M](int a, int b) {
            return customSort(a, b, M);
        });
        
        // 結果を出力
        cout << N << " " << M << endl;
        for (int num : numbers) {
            cout << num << endl;
        }
    }
    
    cout << "0 0" << endl;  // 最後の 0 0 を出力
    
    return 0;
}

// あんま理解できなかった△



