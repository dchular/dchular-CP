#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int d,t,s;
  cin >> d >> t >> s;
  if(d%s == 0){
    if(d/s <= t) cout << "Yes";
    else cout << "No";
  }
  else{
    if(d/s+1 <=t) cout << "Yes";
    else cout << "No";
  }
  return 0;
}
