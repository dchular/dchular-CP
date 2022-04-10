#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
//#include <bits/stdc++.h>
// @coder ABC196
//#define rep(i,a,n) for (int i=a;i<n;i++)
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define rrep(i,a,n) for (int i=n-1;i>=a;i--)

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
/*
テスト通りますように
　　●
　　/⌒ヽ
　 ｜ 　|/⌒ヽ(ヽ
　 (｀　∥ー⌒) |
　|￣||￣￣￣￣￣|
　|―||―――――|
　|　Ｕ　　　　　|
　|￣￣￣￣￣￣￣|
　|＿＿＿＿＿＿＿|
　　|―――――|
　　|―――――|
ｗｗＷｗｗＷｗＷＷｗ
*/

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 200000;
const int MOD = 1e9 + 7;

ll h,w,a,b;
ll ans = 0;
int map[17][17];

void solve(int s12,int s11,int now1,int now2){
  // cout << "map is " << endl;
  // for(int i=0;i<h;i++){
  //   for(int j=0;j<w;j++){
  //     cout << map[i][j];
  //   }
  //   cout << endl;
  // }
  while(map[now1][now2] != 0){
    if(now1+1 < h) now1 ++;
    else if(now2+1 < w){
      now1 = 0;
      now2 ++;
    }
    else {
      ans++;
      return;
    }
  }
  //cout << now1 << ' ' << now2 << endl << endl;
  if(s12 > 0){
    // 1x2
    // **
    if(now1 + 1 < h){
      if(map[now1+1][now2] == 0){
        s12 --;
        map[now1][now2] = 2;
        map[now1+1][now2] = 2;
        solve(s12,s11,now1,now2);
        map[now1][now2] = 0;
        map[now1+1][now2] = 0;
        s12++;
      }
    }
    // 1x2
    // *
    // *
    // ↑多分逆だけど気にしない
    if(now2 + 1 < w){
      if(map[now1][now2+1] == 0){ // 多分ありえないけど気にしない
        s12 --;
        map[now1][now2] = 2;
        map[now1][now2+1] = 2;
        solve(s12,s11,now1,now2);
        map[now1][now2] = 0;
        map[now1][now2+1] = 0;
        s12++;
      }
    }
  }
  if(s11 > 0){
    // 1x1
    // *
    map[now1][now2] = 1;
    solve(s12,s11-1,now1,now2);
    map[now1][now2] = 0;
    //mapが共通財産なの忘れてた
  }
  return ;
}

int main(){
  cin >> h >> w >> a >> b;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      map[i][j] = 0;
    }
  }
  solve(a,b,0,0);
  cout << ans;
  return 0;
}
