#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int x;
  cin >> x;
  x = x - 400;
  if(x%200 == 0){}
  x = x / 200;
  if(8-x < 1) cout << "1";
  else
    cout << 8 - x;
  return 0;
}
