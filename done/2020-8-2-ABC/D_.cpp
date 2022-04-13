#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n;
  string c;
  cin >> n >> c;
  int c1=0,c2=0,c3=0,c4=0;
  for(int i=0;i<n;i++){
    if(c[i] == 'R')
      c1++;
  }
  for(int i=0;i<c1;i++){
    if(c[i] == 'W')
      c2++;
  }
  cout << c2;
  return 0;
}
