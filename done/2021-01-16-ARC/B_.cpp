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
  int n,k;
  int memo[300005] = {0};
  vector<int> vec;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    memo[a] ++;
  }
  int mx = memo[0];
  long long ans = 0;
  for(int i=1;i<=n;i++){
    if(mx > memo[i]){
      for(int j=0;j<mx-memo[i];j++){
        vec.push_back(i);
      }
      mx = memo[i];
    }
  }
  sort(vec.begin(),vec.end());
  // for(int i=0;i<vec.size();i++){
  //   cout << vec[i] << endl;
  // }
  for(int i=vec.size()-1;i>=0;i--){
    if(k == 0) break;
    ans += vec[i];
    k--;
  }
  cout << ans;
}
