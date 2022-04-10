#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  ll a[405];
  cin >> n;
  ll ans = 0;

  for(int i = 0; i <= 400;i++)
    a[i] = 0;
  for(int i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    tmp += 200;
    a[tmp]++;
  }
  for(int i=0; i <= 400;i++){
    for(int j=i+1;j<=400;j++){
      if(a[i] !=0 && a[j] != 0){
        ans += (j - i) * (j - i) * a[i] * a[j];
      }
    }
  }
  cout << ans;
  return 0;
}
