#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;

int main(){
  int n,x;
  string s;
  cin >> n >> x >> s;
  for(int i=0;i<s.size();i++){
    if(s[i] == 'o'){
      x++;
    }
    else{
      if(x>0)
        x--;
    }
  }
  cout << x;
  return 0;
}
