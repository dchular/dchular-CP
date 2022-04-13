#include <iostream>

using namespace std;

int main(){
  int n;
  int w[100];
  cin >> n;
  for(int i = 0;i < n;i ++) {
    cin >> w[i];
  }
  long long s1 = 0,s2 = 0,ans = 0;
  for(int i = 0; i < n; i++){
    s2+= w[i];
  }
  ans = s2;
  for(int i = 0; i < n; i++){
    s1 += w[i];
    s2 -= w[i];
    if(ans > abs(s2-s1) )
      ans = abs(s2-s1);
  }
  cout << ans;
  return 0;
}
