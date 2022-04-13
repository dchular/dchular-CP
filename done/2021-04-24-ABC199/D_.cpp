#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
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
const ll MAX = 5 * 1e2;
const int MOD = 1e9 + 7;;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int connected[25][25];
vector<ll> c[25];
pair<int,int> cnt[25];
int color[25];
ll n,m;
ll ans = 0;
int aa[25];

void solve(ll i){
    if(i == n || cnt[i].first == 0){
    //  cout << i << endl;
      ans++;
      return;
    }
    int f1=1,f2=1,f3=1;
    int now = aa[i];
    rep(j,c[now].size()){
      ll check = c[now][j];
      if(color[check] == 1) f1 = 0;
      if(color[check] == 2) f2 = 0;
      if(color[check] == 3) f3 = 0;
    }
    if(f1){
      color[now] = 1;
      solve(i+1);
      color[now] = 0;
    }
    if(f2){
      color[now] = 2;
      solve(i+1);
      color[now] = 0;
    }
    if(f3){
      color[now] = 3;
      solve(i+1);
      color[now] = 0;
    }
    return;
}

int main(){
  cin >> n >> m;
  rep(i,n){
    color[i] = 0;
    cnt[i] = mp(0,i);
  }
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    connected[a][b] = 1;
    connected[b][a] = 1;
    c[a].pb(b);
    c[b].pb(a);
    cnt[a].first++;
    cnt[b].first++;
  }
  rep(i,n){
    cnt[i].first *= -1;
  }
  sort(cnt,cnt+n);
  rep(i,n){
    cnt[i].first *= -1;
  }
  int aaa = 0;
  rep(i,n){
    aa[i] = cnt[i].second;
    if(cnt[i].first == 0){
      aaa = n - i;
      n = i;
      break;
    }
  }
  // rep(i,n){
  //   cout << cnt[i].first << ' ';
  // }
  // cout << endl;
  // rep(i,n){
  //   cout << aa[i] << ' ';
  // }
  // cout << endl;

  solve(0);
  rep(i,aaa){
    ans *=3;
  }
  cout << ans;

  return 0;
}
