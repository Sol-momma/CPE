#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

  for(int i=0;i<n;i++){
  int total,gap,a,b;
  cin>>total>>gap;
  a=(total+gap)/2;
  b=(total-gap)/2;

  if(b>0&&a+b==total&&a-b==gap)
  cout<<a<<" "<<b<<endl;
  else
  cout<<"impossible"<<endl;
 }
} 

// 理解できるが書けない〇

// 最初にN回ループを回すことを指定する
// この問題は a=(total+gap)/2;
//   b=(total-gap)/2;　がポイント
// aは大きい方のスコア
// bは小さい方のスコア

