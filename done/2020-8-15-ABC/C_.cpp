#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  long long x,k,d;
  cin >> x >> k >> d;
  if(x < 0) x*= -1;
  if(x/d < k) {k -= x/d;x = x % d;}
  else {cout << x - d*k << endl; return 0;}

  if(k % 2 == 0) cout << x << endl;
  else cout << d-x << endl;
  return 0;
}
