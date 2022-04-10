#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int ans;
  int n;
  cin >> n;
  n = n%40;
  if(n<=20) ans = n;
  else {
    n -= 20;
    ans = 21-n;
  }
  cout << ans << endl;
  return 0;
}
