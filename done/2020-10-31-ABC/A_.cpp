#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  long long a,b,c;
  long long d = 998244353;
  cin >> a >> b >> c;
  long long ans = (a * (a+1) / 2 ) % d;
  if(b % 2 == 0){
    ans *= b / 2;
    ans = ans%d;
    ans *= b+1;
    ans = ans%d;
  }
  else {
    ans *= (b+1) / 2;
    ans = ans%d;
    ans *= b;
    ans = ans%d;
  }
  if(c % 2 == 0){
    ans *= c / 2;
    ans = ans%d;
    ans *= c+1;
    ans = ans%d;
  }
  else {
    ans *= (c+1) / 2;
    ans = ans%d;
    ans *= c;
    ans = ans%d;
  }
  cout << ans;
  return 0;
}
