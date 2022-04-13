#include <bits/stdc++.h>
//#include <atcoder/lazysegtree>
//#include <atcoder/segtree>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i,a,n) for (int i=n-1;i>=a;i--)
#define ALL(x) x.begin(),x.end()

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pause "read -p 'Press Enter to continue...' var"

using namespace std;
//using namespace atcoder;

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
typedef vector<pll> vpll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 100005;
const int MOD = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vll v;
ll ans = 0;
ll n,x,y;

void solve(){
  ll sz = v.size();
  ll ng = 0;
  ll X = 0;
  ll Y = 0;
  ll XY = 0;

  ll Xin = -1;
  ll Yin = -1;
  rep(sz){
    if(v[i] == x && v[i] == y){
      if(Xin != -1){
        XY += Xin + 1;
        XY += 1;
      }
      if(Xin == -1) XY++;
      Xin = i;
      Yin = i;
    }
    else if(v[i] == x){
      if(Yin != -1){
        // cout << Yin + 1 << endl;
        XY += Yin + 1;
      }
      Xin = i;
    }
    else if(v[i] == y){
      if(Xin != -1){
        // cout << Xin + 1 << endl;
        XY += Xin + 1;
      }
      Yin = i;
    }
    else{
      if(Xin != -1 && Yin != -1){
        XY += min(Xin,Yin) + 1;
      }
    }
  }
  ans += XY;
  return;
}

int main(){
  cin >> n >> x >> y;
  vll a(n+1);
  rep(n){
    cin >> a[i];
  }
  a.pb(-1);
  rep(n+1){
    if(a[i] > x || a[i] < y){
      if(v.size() != 0) solve();
      v.clear();
    }
    else v.pb(a[i]);
  }
  cout << ans << endl;
  return 0;
}
