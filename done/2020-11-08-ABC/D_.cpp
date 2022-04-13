#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  int n;
  int a[200000];
  long long sum[200000];
  long long ans = 0;
  long long summx = 0;
  long long sumrecord = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(i!=0) sum[i] = sum[i-1] + a[i];
    else sum[i] = a[i];
  }
  for(int i=0;i<n;i++){
    summx = max(summx,sum[i]);
    ans = max(ans,summx + sumrecord);
    sumrecord += sum[i];
  }
  cout << ans << endl;
  return 0;
}
