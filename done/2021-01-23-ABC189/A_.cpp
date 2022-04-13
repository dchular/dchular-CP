#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  string c;
  cin >> c;
  char ch = c[0];
  int flag = 1;
  for(int i=0;i<c.size();i++){
    if(c[i] != ch) flag = 0;
  }
  if(flag) cout << "Won" << endl;
  else cout << "Lost" << endl;
  return 0;
}
