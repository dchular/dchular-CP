#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  if(a*b > 0) cout << b-a << endl;
  else cout << b-a-1 << endl;
  return 0;
}
