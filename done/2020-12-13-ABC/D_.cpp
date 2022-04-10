#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
  int n,m;
  int a[200005];
  int masu[200005];
  cin >> n >> m;
  for(int i=0;i<m;i++){
    cin >> a[i];
  }
  sort(a,a+m);
  int gcdd = 1;
  masu[0] = a[0]-1;
  if(masu[0] < 0) masu[0] = 0;
  if(masu[0] != 0) gcdd = masu[0];
  for(int i=1;i<m;i++){
    masu[i] = a[i] - a[i-1] -1;
    if(masu[i] != 0) gcdd = masu[i];
  }
  masu[m] = n - a[m-1];
  for(int i=0;i<=m;i++){
    if(masu[i] != 0){
      gcdd = min(gcdd,masu[i]);
    }
  }
  long long ans = 0;
  //cout << "gcdd = " << gcdd << endl;
  int cnt = 0;
  for(int i=0;i<=m;i++){
    if(masu[i] != 0){
      cnt ++;
      //cout << i << " masu[i] = " << masu[i] << endl;
      ans += masu[i] / gcdd;
      if(masu[i] % gcdd != 0) ans++;
    }
  }
  if(cnt == 1) cout << "1";
  else cout << ans << endl;
  return 0;
}
