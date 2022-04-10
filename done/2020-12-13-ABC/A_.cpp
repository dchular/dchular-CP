#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int a1,a2,a3,a4;
  cin >> a1 >> a2 >> a3 >> a4;
  int ans = a1;
  ans = min(ans,a2);
  ans = min(ans,a3);
  ans = min(ans,a4);
  cout << ans;
  return 0;
}
