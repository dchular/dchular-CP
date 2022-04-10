#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n;
  long long a[200005] = {0};
  long long sum = 0;
  long long ans = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum = sum + a[i];
    sum = sum % 1000000007;
    //cout << sum << ' ';
  }
  //cout << endl << endl;
  for(int i=0;i<n-1;i++){
    sum -= a[i];
    if(sum < 0) sum+= 1000000007;
    long long tmp = (long long)a[i] * (long long)sum;
    tmp = tmp % 1000000007;
    ans += tmp;
    ans = ans % 1000000007;
    //cout << sum << ' ' << ans << endl;
  }
  if(ans < 0) ans += 1000000007;
  cout << ans;

  // long long sum2 = 0;
  // for(int i=0;i<n-1;i++){
  //   for(int j=i+1;j<n;j++){
  //     sum2 = sum2 + a[i] * a[j];
  //     sum2 = sum2 % 1000000007;
  //   }
  // }
  // //1000000000
  // cout << sum2 << endl;
  return 0;
}
