#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;
typedef long long ll;
#define mp make_pair

int main(){
  int n,m,q;
  int x[55];
  vector < pair<int,int> > ve;
  cin >> n >> m >> q;
  for(int i=0;i<n;i++){
    int t1,t2;
    cin >> t1 >> t2;
    ve.push_back(mp(t1,-1*t2));
  }
  //cout << endl;
  sort(ve.begin(),ve.end());
  for(int i=0;i<n;i++){
    ve[i].second *= -1;
    //cout << ve[i].first << ' ' << ve[i].second << endl;
  }
  for(int i=0;i<m;i++)
    cin >> x[i];
  for(int j=0;j<q;j++){
    int a,b;
    cin >> a >> b;
    vector <int> xx;
    for(int i=0;i<m;i++){
      if(i+1 >= a && i+1 <= b) continue;
      else xx.push_back(x[i]);
    }
    ll ans = 0;
    sort(xx.begin(),xx.end());
    int map[55] = {0};
    for(int i=0;i<xx.size();i++){
      int flag = 0;
      int mx = 0;
      int index = 0;
      for(int k=0;k<ve.size();k++){
        if(map[k] != 0) continue;
        if(xx[i] < ve[k].first) {
          flag = -1;
          break;
        }
        if(mx < ve[k].second){
          mx = ve[k].second;
          index = k;
        }
      }
      if(mx != 0){
        ans += mx;
        map[index] = -1;
      }
    }
    cout << ans << endl;
  }
}
