#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
long long k,cnt = 0;
int t[10][10];
int flag[10] = {0};

void solve(int now,long long sum){
  bool endflag = true;
  for(int i=0;i<n;i++){
    if(flag[i] == 0){
      endflag = false;
      break;
    }
  }
  if(endflag){
    sum += t[now][0];
    //cout << sum << endl;
    if(sum == k) cnt++;
    return;
  }
  if(sum > k) return;
  for(int i=0;i<n;i++){
    if(flag[i] == 0){
      flag[i] = 1;
      solve(i,sum + t[now][i]);
      flag[i] = 0;
    }
  }
  return;
}

int main(){
  cin >> n >> k;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> t[i][j];
    }
  }
  flag[0] = 1;
  solve(0,0);
  cout << cnt;
  return 0;
}
