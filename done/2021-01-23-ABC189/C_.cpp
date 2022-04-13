#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  int a[10005] = {0};
  int ans = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    int mi = a[i];
    for(int j=i;j<n;j++){
      mi = min(mi,a[j]);
      ans = max(ans,(j-i+1) * mi);
    }
  }
  cout << ans << endl;
}
