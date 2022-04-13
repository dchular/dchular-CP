#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  double x,y;
  cin >> x >> y;
  if(y == 0) cout << "ERROR" << endl;
  //else cout << fixed << setprecision(2) << (double)x/y << endl;
  else cout << fixed << setprecision(2)<< std::floor(100 * (x/y)) / 100 << endl;
  return 0;
}
