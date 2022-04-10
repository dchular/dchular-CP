#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(2*a + 100 > b) cout << 2*a+100 - b;
  else cout << "0";
  return 0;
}
