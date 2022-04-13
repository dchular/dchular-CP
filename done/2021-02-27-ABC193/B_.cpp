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
  int n;
  cin >> n;
  int ans = 1000000001;
  for(int i=0;i<n;i++){
    int a,p,x;
    cin >> a >> p >> x;
    if(x <= a) continue;
    ans = min(ans,p);
  }
  if(ans == 1000000001) cout << "-1" << endl;
  else cout << ans << endl;
  return 0;
}
