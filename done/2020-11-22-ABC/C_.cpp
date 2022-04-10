#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
  long long r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  long long x1 = r2-r1;
  long long y1 = c2-c1;
  long long c = x1+y1;
  if(r1 == r2 && c1 == c2){
    cout << "0";
  }
  else if(x1 == y1 || x1 == y1*-1 || x1*x1 + y1*y1 <= 9){
    cout << "1";
  }
  else{
    if(c % 2 == 0){
      cout << "2";
    }

    else{
      double d1 = (double) abs(x1+y1) / sqrt(2);
      double d2 = (double) abs(x1-y1) / sqrt(2);
      if(d1 <= 3 || d2 <= 3){
        cout << "2";
      }
      else{
        cout << "3";
      }
    }
  }

}
