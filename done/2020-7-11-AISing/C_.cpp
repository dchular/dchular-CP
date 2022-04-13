#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int f[10005] = {0};
  // (x+y)^2 + (y+z)^2 + (x+z)^2 = 2n
  cin >> n;
  for(int x=1;x<142;x++){
    if(x*x > 2*n) break;
    for(int y=1;y<142;y++){
      if((x+y) * (x+y) > 2*n) break;
      for(int z=1;z<142;z++){
        int two_n = (x+y) * (x+y) + (y+z)*(y+z) + (x+z)*(x+z);
        //cout << two_n  << ' ' << x << ' ' << y << ' ' << z << endl;
        if(two_n > 2*n) break;
        if(two_n % 2 != 0) continue;
        else f[two_n/2]++;
      }
    }
  }

  for(int i=1;i<n;i++){
    cout << f[i] << endl;
  }
  cout << f[n];
  return 0;
}
