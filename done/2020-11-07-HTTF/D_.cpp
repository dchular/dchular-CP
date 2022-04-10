#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  int n,a[1000005];
  int p[1000] = {0};
  int pcount[1000] = {0};
  int plist[1000]={0};
   cin >> n;
   for(int i=0;i<n;i++){
     cin >> a[i];
   }
  p[0] = -1;
  p[1] = -1;
  int cnt = 0;
  for(int i=0;i<1000;i++){
    pcount[i] =0;
  }
  for(int i=2;i<1000;i++){
    if(p[i] == 0){
      p[i] = 1;
      plist[cnt] = i;
      cnt++;
      //cout << i << ' ';
      for(int j=2;j * i < 1000;j++)
        p[j*i] = -1;
    }
  }
  int flag1 = 1,flag2 = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<cnt;j++){
      if(a[i] % plist[j] == 0){
        if(pcount[ plist[j] ] != 0) flag1 = 0;
        pcount[ plist[j] ] ++;
      }
    }
  }
  cout << cnt;
  if(flag1){
    cout << "pairwise coprime";
    return 0;
  }
  //int tmp = 0;
//  for(int i=0;i<10;i++){
  //  cout << pcount[i] << ' ';
  //}
  for(int i=0;i<1000;i++){
    if(pcount[i] == n){
      flag2 = 0;
      //cout << "not coprime";
      //return 0;
    }
  }
  if(flag2){
    cout << "setwise coprime";
    return 0;
  }
  cout << "not coprime";
  return 0;
}
