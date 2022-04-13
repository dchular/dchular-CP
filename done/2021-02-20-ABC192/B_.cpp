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
  string s;
  cin >> s;
  int flag = 1;
  for(int i=0;i<s.size();i++){
    if(i%2 == 0){
      if(s[i] >= 'a' && s[i] <= 'z'){

      }
      else flag = 0;
    }
    if(i%2 == 1){
      if(s[i] >= 'A' && s[i] <= 'Z'){

      }
      else flag = 0;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
