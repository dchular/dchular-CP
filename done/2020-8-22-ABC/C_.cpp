#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,max_height = -1;
  int a[200005] = {0};
  long long ans = 0;
  cin >> n;
  cin >> a[0];
  max_height = a[0];
  for(int i=1;i<n;i++){
    cin >> a[i];
    if(a[i] < max_height) {
      ans += max_height - a[i];
    }
    else {
      max_height = a[i];
    }
  }
  cout << ans;
  return 0;
}
