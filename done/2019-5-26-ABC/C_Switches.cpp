#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

int n,m;
int k[10],s[10][10],p[10];
int swch[10] = {0};
int ans = 0;
int enkh = 0;

void solve(int cnt,int sw[10]){
  if(cnt == -1){
    int flag = 1;
    for(int i = 0; i < m ; i++){
      if(!flag) break;
      int temp = 0;
      //printf("k[%d] = %d\n",i,k[i]);
      for(int j = 0; j < k[i]; j++){
        if(sw [ s[i][j]-1 ] == 1) temp++;
        //printf("s[%d][%d] = %d\n",i,j,s[i][j]);
      }
      temp = temp % 2;
      //printf("i:%d temp:%d\n",i,temp);
      if(p[i] == temp) flag = 1;
      else flag = 0;
    }

    if(flag) ans++;
    return ;
  }
  sw[cnt] = 0;
  solve(cnt-1,sw);
  sw[cnt] = 1;
  solve(cnt-1,sw);
  return ;
}

int main(){
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    cin >> k[i];
    //printf("\nhere : k[%d] = %d\n",i,k[i]);
    for(int j = 0; j < k[i] ; j++){
      cin >> s[i][j];
    }
  }

  for(int i = 0; i < m ; i++)
    cin >> p[i];

  solve(n-1,swch);

  cout << ans;
  return 0;
}
