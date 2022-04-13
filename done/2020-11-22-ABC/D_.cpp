#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

double dp[101][101][101];
int flag[101][101][101];

double solve(int a, int b,int c){
  if(dp[a][b][c] != -1) return dp[a][b][c];
  if(a > 99 || b > 99 || c > 99) return 0;
  dp[a][b][c] = 0;
  double ea = (double) a / (double)(a + b + c);
  double eb = (double) b / (double)(a + b + c);
  double ec = (double) c / (double)(a + b + c);
  cout << ea << eb << ec;
  dp[a][b][c] += solve(a+1,b,c) + ea;
  dp[a][b][c] += solve(a,b+1,c) + eb;
  dp[a][b][c] += solve(a,b,c+1) + ec;

  return dp[a][b][c];
  //全然わからん、普通にE問題解いとけばよかったa-zのリスト作ってbfsすればいいだけだし
}

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  // for(int i=a;i<=100;i++){
  //   for(int j=b;j<=100;j++){
  //     for(int k=c;k<=100;k++){
  //       dp[i][j][k] = -1;
  //     }
  //   }
  // }
  for(int i=99;i>=a;i--){
    for(int j=99;j>=b;j--){
      for(int k=99;k>=c;k--){
        double tmp = i+j+k;
        dp[i][j][k] += (dp[i+1][j][k] + 1) * (double(i) / tmp);
        dp[i][j][k] += (dp[i][j+1][k] + 1) * (double(j) / tmp);
        dp[i][j][k] += (dp[i][j][k+1] + 1) * (double(k) / tmp);
      }
    }
  }
  printf("%.12f", dp[a][b][c]);
  //printf("%.12f", solve(a,b,c));
  return 0;
}
