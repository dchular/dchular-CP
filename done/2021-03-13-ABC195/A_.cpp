#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
  ll m,h;
  cin >> m >> h;
  if(h % m == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
