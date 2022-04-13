#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int ans = 0;
  string n;
  cin >> n;
  for(int i=0;i<n.size();i++){
    int tmp = n[i] - '0';
    ans = (ans + tmp) %9;
  }
  if(ans == 0) cout << "Yes";
  else cout << "No";
  return 0;
}
