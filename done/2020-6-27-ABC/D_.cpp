#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;
string s[2000];
int ans = 0,h,w;
int L[2000][2000] = {0};
int R[2000][2000] = {0};
int D[2000][2000] = {0};
int U[2000][2000] = {0};

int main(){
  cin >> h >> w;
  for(int i = 0; i < h; i++){
    cin >> s[i];
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(i == 0) U[i][j] = ( 0 + 1 ) * (s[i][j] == '.');
      else U[i][j] = ( U [i-1] [j] + 1 ) * (s[i][j] == '.');
      if(j == 0) L[i][j] = ( 0 + 1 ) * (s[i][j] == '.');
      else L[i][j] = ( L[i][j-1] + 1) * (s[i][j] == '.');
    }
  }
  for(int i = h-1; i >= 0; i--){
    for(int j = w-1; j >=0; j--){
      if(i == h-1) D[i][j] = ( 0 + 1 ) * (s[i][j] == '.');
      else D[i][j] = ( D [i+1] [j] + 1 ) * (s[i][j] == '.');
      if(j == w-1) R[i][j] = ( 0 + 1 ) * (s[i][j] == '.');
      else R[i][j] = ( R[i][j+1] + 1) * (s[i][j] == '.');
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      ans = max(ans, U[i][j] + D[i][j] + L[i][j] + R[i][j]);
    }
  }
  // for(int i = 0; i < h; i++){
  //   for(int j = 0; j < w; j++){
  //       printf("%.2d ", L[i][j]);
  //   }
  //   cout << endl;
  // }
  cout << ans - 3;
  return 0;
}
