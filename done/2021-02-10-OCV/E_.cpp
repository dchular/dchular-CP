#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int n,m;
ll int_max = 2147483647;
ll a[2005];
ll b[2005];
ll c[2005];
vector< pair<ll,ll> > ve[2005];
ll dp[2005][2005];
ll temp[2005][2005];
ll come[2005];

void solve(ll now,ll goal,ll cost){
  if(cost != 0 && now == goal){
    dp[now][goal] = min(cost,dp[now][goal]);
    return ;
  }
  //cout << now << " " << goal << " " << cost << " " << dp[goal][now] << endl;
  if(come[now] != goal){
    come[now] = goal;
    for(int i=0;i< ve[now].size();i++){
      solve(ve[now][i] . first, goal, cost + ve[now][i] .second);
    }
  }
  else{

  }
  return;
  // if(dp[goal][now] != int_max) {
  //   dp[goal][now] = min(dp[goal][now],cost);
  //   return ;
  // }
  // else{
  //   for(int i=0;i<ve[now].size();i++){
  //
  //     solve(ve[now][i] . first, goal, cost + ve[now][i] .second);
  //     dp[goal][ve[now][i] . first] = min(dp[goal][ve[now][i].first],cost + ve[now][i] .second);
  //   }
  // }
  // if(cost != 0)
  //   dp[goal][now] = min(dp[goal][now],cost);
  // return ;
}

int main(){

  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      dp[i][j] = int_max;
      come[i] = -1;
      temp[i][j] = -1;
    }
  }
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    //dp[ a[i] ] [ b[i] ] = c[i];
    if(temp[ a[i] ] [ b[i] ] != -1){
      //cout << endl << a[i] << ' ' << b[i] << ' ' << c[i] << endl << endl;
      for(int j=0;j< ve[ a[i] ].size();j++){
        if(ve[ a[i] ] [j] .first == b[i]){
          ve[ a[i] ] [j] .second = min(ve[ a[i] ] [j] .second , c[i]);
        }
      }
    }
    else{
      temp[ a[i] ] [ b[i] ] = 1;
      ve[ a[i] ] .push_back(make_pair(b[i],c[i])) ;
    }
  }
  for(int i=0;i<n;i++){
    solve(i,i,0);
    if(dp[i][i] == int_max) cout << "-1" << endl;
    else cout << dp[i][i] << endl;
  }
  return 0;
}
