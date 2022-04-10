#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,x,t;
  cin >> n >> x >> t;
  int tmp = n%x;
  if(tmp == 0) cout << (n/x) *t;
  else cout << (n/x +1) *t;
  return 0;
}
