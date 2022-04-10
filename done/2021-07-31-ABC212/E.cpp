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
const int MOD = 998244353;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

const int n_max = 5005;
vll G[n_max];

int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  rep(m){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  rep(n) G[i].pb(i);
  static ll dp[5005][5005] = {0};
  dp[0][0] = 1;
  rep(i,1,k+1){
    ll sum = 0;
    rep(j,n){
      sum += dp[i-1][j];
      sum %= MOD;
    }
    rep(j,n){
      dp[i][j] = sum;
      for(ll unc: G[j]){
        dp[i][j] -= dp[i-1][unc];
        dp[i][j] += MOD;
        dp[i][j] %= MOD;
      }
    }
    // cout << "k = " << i << ':';
    // rep(j,n) cout << dp[i][j] << ' ';
    // cout << endl;
  }
  cout << dp[k][0] << endl;
  return 0;
}
