#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  double v,t,s,d;
  cin >> v >> t >> s >> d;
  if(d / v >= t && d/v <= s) cout << "No";
  else cout << "Yes";
  return 0;
}
