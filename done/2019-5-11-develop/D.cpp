#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

// n = i*k + k = k*(i+1)
// i > k

int main(){
  int n,ans=0;
  cin >> n;
  for(int k = 1 ;k*k < n ; k++){
    if(n%k == 0 && n/k - 1 > k){
      ans+= n/k - 1;
    }
  }
  cout << ans;
  return 0;
}
