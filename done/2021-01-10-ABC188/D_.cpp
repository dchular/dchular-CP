#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m,x,y;
int a[200005];
int f[200005] = {0};
vector<int> v[200005];
int color = 1;
int ans = -1000000000;

void memo(int index){
  int mx = a[index];
  int here = mx;
  int tmp = -1;
  for(int i=0;i<v[index].size();i++){
    a[index] = max(a[index],a[v[index][i]]);
    tmp = max(tmp,a[v[index][i]]);
  }
  //cout << "index: " << index << " here = " << here << " mx = " << a[index] << endl;
  if(a[index] != here) ans = max(ans,a[index] - here);
  else if(tmp != -1){
    ans = max(ans,tmp - a[index]);
  }
}

int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> a[i];
    f[i] = -1;
  }
  for(int i=0;i<m;i++){
    cin >> x >> y;
    v[x-1].push_back(y-1);
  }
  for(int i=n-1;i>=0;i--){
    memo(i);
  }
  cout << ans;
  return 0;
}
