#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  ll a[1005];
  ll b[1005];
  cin >> n;
  ll ans = 10000005;
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ll tmp;
      if(i == j)
        tmp = a[i] + b[j];
      else
        tmp = max(a[i],b[j]);
      ans = min(ans,tmp);
    }
  }
  cout << ans;
  return 0;
}
