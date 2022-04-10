#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

int main(){
  int n,cnt=0;
  cin >> n;
  int v[100000][2] = {0};
  int ans[100000];
  int flag[100000];
  vector<pair<int,int> > map[100000];
  for(int i =0; i<n;i++){
    ans[i] = 1;
    flag[i] = 0;
  }
  for(int i = 0; i < n-1; i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    map[i].push_back(make_pair(a,c%2));
    map[i].push_back(make_pair(b,c%2));
    if(c%2 == 0){
      v[i][0]++;
      if(a!=i) v[a][0]++;
      v[b][0]++;
    }
    else{
      v[i][1]++;
      if(a!=i) v[a][1]++;
      v[b][1]++;
    }
  }

  for(int i=0;i<n;i++){
    if(v[i][1] == 0){
      ans[i] = 0;
      flag[i] = 1;
      cnt++;
    }
  }
  // int temp = 0;
  // while(cnt!=n){
  //   if(temp == 0)
  //     temp = 1;
  //   else
  //     temp = 0;
  //
  for(int i=0;i<n;i++){
    if(v[i][0] !=0 && v[i][1] > 0)
      ans[i] = 1;
  }
  for(int i=0;i<n;i++){
    //cout << v[i][0] << ' ' << v[i][1] << ' ' << i << endl;
    if(v[i][0] ==0 && v[i][1] > 0)
      ans[i] = 0;
  }
  for(int i=0;i<n;i++){
    cout << ans[i] << endl;
  }

  return 0;
}
