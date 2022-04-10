#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;

int main(){
  int n,m,t;
  cin >> n >> m >> t;
  //cout << m << endl;
  int now = 0;
  int flag = 1;
  int maxn = n;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    int minus = a - now;
    if(n <= minus) {
      flag = 0;
      break;
    }
    n -= minus;
    int plus = b-a;
    if(n + plus >= maxn)
      n = maxn;
    else
      n += plus;
    now = b;
  }
  int minus = t - now;
  if(n <= minus)
    flag = 0;
  if(flag) cout << "Yes";
  else cout << "No";
  return 0;
}
