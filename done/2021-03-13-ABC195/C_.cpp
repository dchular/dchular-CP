#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  if(n < 1000) ans += 0;
  if(n >= 1000){
    ans += n-999;
  }
  if(n >= 1000000){
    ans += (n-999999);
  }
  if(n >= 1000000000){
    ans += (n-999999999);
  }
  if(n >= 1000000000000){
    ans += (n-999999999999);
  }
  if(n >= 1000000000000000) {
    ans += (n-999999999999999);
  }

  cout << ans << endl;
  return 0;
}
