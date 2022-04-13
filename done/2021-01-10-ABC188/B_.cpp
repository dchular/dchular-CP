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
  int n;
  cin >> n;
  int a[100005];
  int b[100005];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  for(int i=0;i<n;i++){
    a[i] *= b[i];
  }
  sort(a,a+n);
  long long ans = 0;
  for(int i=0;i<n/2;i++){
    ans += a[i];
    ans += a[n-1-i];
  }
  if(n%2 == 1) ans += a[n/2];
  if(ans == 0) cout << "Yes";
  else cout << "No";
  return 0;
}
