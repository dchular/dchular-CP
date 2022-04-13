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
  vector<int>  a;
  cin >> n >> m;

  for(int i = 0; i < n; i ++){
    int t;
    cin >> t;
    a.push_back(t);
  }

  for(int i = 0; i < m; i ++){
    int t1,t2;
    cin >> t1 >> t2;
    for(int j = 0; j < t1; j ++)
      a.push_back(t2);
  }
  sort(a.begin(),a.end());
  long long sum =0;
  //for(int i=0;i<a.size();i++) cout << a[i] << ' ';
  //cout << endl;
  for(int i=0;i<n;i++){
    sum += a[a.size()-i-1];
    //cout << i << ' ' << a[a.size()-i-1] << endl;
  }
  cout << sum;
  return 0;
}
