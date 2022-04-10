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
  int n,x;
  cin >> n >> x;
  double now = 0;
  int ans = -1;
  for(int i=0;i<n;i++){
    double v,p;
    cin >> v >> p;
    now += v * p;
    if(now > x*100){
      ans = i+1;
      break;
    }
  }
  cout << ans;
}
