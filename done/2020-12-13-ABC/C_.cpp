#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
  int l;
  unsigned long long ans = 1;
  int check[13] = {0};
  cin >> l;
  for(int i=1;i<12;i++){
    ans *= l-i;
    for(int j=1;j<12;j++){
      if(check[j] == 0 && ans%j == 0){
        check[j] = 1;
        ans /= j;
      }
    }
  }
  // for(int i =1;i<12;i++){
  //   ans /= i;
  // }
  if(l == 12) ans = 1;
  cout << ans;
}
