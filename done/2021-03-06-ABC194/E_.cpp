#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
typedef long long ll;

int main(){
  ll n,m;
  cin >> n >> m;
  int a[1500005] = {0};
  int now[1500005] = {0};
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<m;i++){
    now[a[i]] ++;
  }
  int ans = 0;
  while(1){
    if(now[ans] == 0){
      break;
    }
    ans++;
  }
  for(int i=m;i<n;i++){
    if(a[i-m] < ans && a[i] != a[i-m] && now[a[i-m]] == 1){
      ans = a[i-m];
    }
    now[a[i]] ++;
    now[a[i-m]] --;
  }
  cout << ans;
}
