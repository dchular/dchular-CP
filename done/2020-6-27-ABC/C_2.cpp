#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int n,m,k,cnt=0;
int a[300000] = {0};
int b[300000] = {0};

void solve(int anow, int bnow,int kk){
  cnt = max(cnt,anow+bnow);
  //cout << anow << " " << bnow << " " << kk << endl;
  if(anow == n && bnow == m) return;
  if(kk >= a[anow] && anow < n) solve(anow+1, bnow, kk - a[anow]);
  if(kk >= b[bnow] && bnow < m) solve(anow, bnow+1, kk - b[bnow]);
  return;
}

int main(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }

  solve(0,0,k);

  cout << cnt;
}
