#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int h,w;
char map[2005][2005];
long long sum[2005][2005] = {0};
long long tmp = 1000000007;

int main(){
  cin >> h >> w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> map[i][j];
    }
  }
  sum[0][0] = 1;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      for(int k=j-1;k>=0;k--){
        if(map[i][k] == '#') break;
        sum[i][j] += sum[i][k];
        sum[i][j] = sum[i][j] % tmp;
      }
      for(int k=i-1;k>=0;k--){
        if(map[k][j] == '#') break;
        sum[i][j] += sum[k][j];
        sum[i][j] = sum[i][j] % tmp;
      }
      int k1 = i-1;
      int k2 = j-1;
      while(1){
        if(k1 < 0 || k2 < 0) break;
        if(map[k1][k2] == '#') break;
        sum[i][j] += sum[k1][k2];
        sum[i][j] = sum[i][j] % tmp;
        k1--;
        k2--;
      }
    }
  }
  cout << sum[h-1][w-1] % tmp;
  return 0;
}
