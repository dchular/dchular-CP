#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  ll n,cnt = 0;
  int prime[100000] = {0};
  cin >> n;
  for(int i=2;i<=sqrt(n);i++){
    int flag = 0;
    for(int j=2;j<=sqrt(i);j++){
      if(i%j == 0){
        flag = -1;
        break;
      }
    }
    if(flag == 0){
      prime[cnt++] = i;
      //cout << i << endl;
    }
  }
  ll ans = 0;
  vector<ll> aa;
  ll cnt2 = 0;
  ll s = sqrt(n);
  map<ll,bool> m;
  for(ll i=2;i<=s;i++){
    int flag = 1;
    if(m.find(i) != m.end()) flag = 0;
    // for(int k=0;k<aa.size();k++){
    //   if(i == aa[k]) {
    //     flag = 0;
    //     aa.erase(aa.begin() + k);
    //     break;
    //   }
    //   if(i < aa[k]) break;
    // }
    // for(int k=0;k<cnt;k++){
    //   ll tmp = i;
    //   if(tmp == prime[k]) {
    //     flag = 2;
    //     break;
    //   }
    //   while(1){
    //     if(tmp % prime[k] == 0){
    //       tmp /= prime[k];
    //     }
    //     else break;
    //   }
    //   if(tmp == 1){
    //     flag = 0;
    //     break;
    //   }
    // }
    if(flag == 0) continue;
    // if(flag == 1){
    //   prime[cnt++] = i;
    // }
    ll j = i * i;
    while(1){
      if(j <= n) {
        ans++;
        m.insert(make_pair(j,true));
        // aa.push_back(j);
        // sort(aa.begin(),aa.end());
        //cout << j << endl;
      }
      else break;
      j *= i;
    }
  }
  cout << n - ans << endl;
  return 0;
}
