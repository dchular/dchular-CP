#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
//#include <bits/stdc++.h>
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
const ll MOD = 998244353;

ll h,w,x,y;
ll ans = 0;
string s[105];

int main(){
  cin >> h >> w >> x >> y;
  rep(i,h){
    cin >> s[i];
  }
  x--;
  y--;
  int xx = x+1;
  while(s[xx][y] == '.' && xx < h){
    xx++;
    ans++;
  }
  xx = x-1;
  while(xx >= 0 && s[xx][y] == '.'){
    xx--;
    ans++;
  }
  int yy = y+1;
  while(s[x][yy] == '.' && yy < w){
    yy++;
    ans++;
  }
  yy = y-1;
  while( yy >= 0 && s[x][yy] == '.'){
    yy--;
    ans++;
  }
  if(s[x][y] == '.') ans++;
  cout << ans;
  return 0;
}
