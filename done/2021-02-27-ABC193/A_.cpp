#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  double a,b;
  cin >> a >> b;
  double c = b/a;
  c = 1-c;
  c *= 100;
  cout << c << endl;
  return 0;
}
