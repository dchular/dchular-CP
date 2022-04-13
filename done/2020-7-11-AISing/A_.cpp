#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int l,r,d,cnt=0;
  cin >> l >> r >> d;
  for(int i=l;i<=r;i++){
    if(i % d ==0)
      cnt++;
  }
  cout << cnt;
  return 0;
}
