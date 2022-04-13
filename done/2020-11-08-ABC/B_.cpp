#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;

int gcd(int x, int y) {
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
        //x%y==0でないときはユーグリットの互除法を使って再帰的に関数を呼び出す。
    }
}

int main(){
  int n,ans = 0,ansindex = 0;
  int a[100];
  int map[1001] = {0};
  cin >> n;
  for(int i=0;i<=1000;i++) map[i] = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=2;j<=1000;j++){
      if(a[i] % j == 0)
        map[j]++;
    }
  }
  for(int i=2;i<=1000;i++){
    if(ans < map[i]){
      ans = map[i];
      ansindex = i;
    }
  }
  if(ansindex == 0) cout << "1" << endl;
  else cout << ansindex << endl;
  return 0;
}
