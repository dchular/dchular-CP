#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  vector<pair<int,int> > v;
  int hozon[65537];
  cin >> n;
  for(int i=0;i<pow(2,n);i++){
    int a;
    cin >> a;
    v.push_back(make_pair(a,i));
  }
  for(int i=n;i>=2;i--){
    vector<int> vec;
    for(int j=0;j<pow(2,i-1);j++){
      if(v[j].first > v[j+1].first) v.erase(v.begin() + j+1);
      else v.erase(v.begin() + j);
    }
    // for(int j=0;j<v.size();j++){
    //   cout << v[j] << " ";
    // }
    // cout << endl;
  }
  int ans;
  if(v[0].first > v[1].first){
    ans = v[1].second;
  }
  else ans = v[0].second;
  cout << ans+1;
}
