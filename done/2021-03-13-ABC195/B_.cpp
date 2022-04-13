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
  ll a,b,w;
  cin >> a >> b >> w;
  w *= 1000;

  if(w % a != 0 && w%b != 0 && w/a == w/b) {
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }
  if(w % b == 0){
    cout << w/b;
  }
  else
    cout << w/b + 1;
  cout << ' ';
  if(w % a == 0){
    cout << w/a;
  }
  else cout << w / a;

  return 0;
}
