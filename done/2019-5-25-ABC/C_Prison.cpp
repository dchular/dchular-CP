#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

int main(){
  int n,m,r,l;
  int l_max = 0, r_min = 1000000;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    if(l_max < l) l_max = l;
    if(r_min > r) r_min = r;
  }

  if(l_max > r_min) cout << 0;
  else cout << r_min - l_max + 1;

  return 0;
}
