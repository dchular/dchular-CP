#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,k;
  long long cnt=0;
  std::vector<int> kk;
  cin >> n >> k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i-k )
      kk.push_back(i+j);
    }
  }
  //for(int i=0;i<kk.size();i++){
  //  cout << kk[i] << endl;
  //}
  int sz = kk.size();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
//      cnt += count(kk.begin(),kk.end(), k+i+j);
      vector<int>:: iterator position = lower_bound(kk.begin(),kk.end(),k+i+j);
      int index = distance(kk.begin(),position);
      while(kk[index] == k + i + j && index < sz){
        cout << i << ' ' << j << ' ' << index << endl;
        cnt ++;
        index ++;
      }
    }
  }
  cout << cnt;
  return 0;
}
