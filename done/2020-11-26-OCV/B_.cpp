#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;
int n,m;
string s[11];
string stmp[11];

int cnt = 0;
int cnttmp = 0;
int cntmax = 0;

void reset(){
  for(int i=0;i<n;i++){
    stmp[i] = s[i];
  }
  cnttmp = 0;
}

void count(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j] == '.')
        cntmax ++;
    }
  }
  cntmax ++;
}

void dfs(int x,int y){
  int xx[5] = {0,-1,+1, 0, 0};
  int yy[5] = {0,0, 0,-1,+1};
  cnttmp++;
  stmp[x] [y] = '#';
  for(int i=0;i<5;i++){
      if(x + xx[i] >= 0 && x + xx[i] < n && y + yy[i] >= 0 && y + yy[i] < m ){
        if(stmp[x + xx[i]] [y+yy[i]] == '.'){
          dfs(x+xx[i] , y+yy[i]);
          //stmp[x + xx[i]] [y+yy[i]] = '.';
        }
      }
  }
}

void solve(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j] == '#'){
        s[i][j] = '.';
        reset();
        dfs(i,j);
    //  cout << cnttmp << endl;
        if(cnttmp == cntmax)
          cnt++;
        s[i][j] = '#';
      }
    }
  }
  return;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  count();
  reset();
  solve();
  cout << cnt;
  return 0;
}
