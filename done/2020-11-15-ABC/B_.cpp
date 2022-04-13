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
  double sx,sy,gx,gy;
  cin >> sx >> sy >> gx >> gy;
  cout << setprecision(10) << fixed << (double) (sy*gx + sx*gy) / (gy + sy);
  return 0;
}
