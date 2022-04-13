#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  if(max(x,y) - min(x,y) < 3) cout << "Yes";
  else cout << "No";
  return 0;
}
