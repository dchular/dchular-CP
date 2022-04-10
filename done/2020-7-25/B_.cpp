#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  for(int i=0;i<k;i++){
    if(a >= b) {
      b *=2;
    }
    else if(b >= c){
      c *=2;
    }
  }
  if(b > a && c > b) cout << "Yes";
  else cout << "No";
  return 0;
}
