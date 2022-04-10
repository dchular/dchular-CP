#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;
typedef pair<int, int> P;
#define mp make_pair
bool cmp(P a, P b){
  return a.first > b.first;
}

int main(){
  int n,m;
  vector<P> c;
  vector<int>  a;
  cin >> n >> m;
  int count = n;
  for(int i = 0; i < n; i ++){
    int t;
    cin >> t;
    a.push_back(t);
  }
  sort(a.begin(),a.end());

  for(int i = 0; i < m; i ++){
    int t1,t2;
    cin >> t1 >> t2;
    c.push_back ( mp(t2,t1) );
  }
  sort(c.begin(),c.end(),cmp);
  for(int i = 0 ; i < n; i++){
    if(c[0].second == 0) break;
    if(a[i] > c[0].first) break;
    else {
      a[i] = c[0].first;
      c[0].second --;
      if(c[0].second == 0){
        c.erase(c.begin());
      }
    }
  }
  long long sum = 0;
  for(int i=0;i<n;i++){
    //cout << a[i] << ' ';
    sum += a[i];
  }
  cout  << sum;
  return 0;
}
