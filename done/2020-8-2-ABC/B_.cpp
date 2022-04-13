#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  long long n,d;
  long long x,y,ans = 0;

  cin >> n >> d;

  for(int i=0;i<n;i++){
    cin >> x >> y;
    if(x*x + y*y <= d*d) ans++;
  }
  cout << ans;
  return 0;
}
