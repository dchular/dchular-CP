#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  long long n,a[205];
  long long dp[200];
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> a[i];
    dp[i] = 0;
  }
  dp[0] = 1000;
  for(int i = 0; i < n ; i ++){
    long long stock = dp[i] / a[i];
    for(int j = i+1; j < n; j ++){
      dp[j] = max(dp[i], dp[i] - stock * a[i] + stock * a[j]);
    }
  }
  cout << dp[n-1];
  return 0;
}
