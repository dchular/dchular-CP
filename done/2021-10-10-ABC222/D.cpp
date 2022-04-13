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

int main(){
  ll n;
  cin >> n;
  ll a[3005];
  ll b[3005];
  static ll dp[3005][3005] = {0};
  rep(n) cin >> a[i];
  rep(n) cin >> b[i];
  rep(i,a[0],b[0]+1) dp[0][i] = 1;
  rep(i,1,n){
    // ll sum[3005] = {0};
    // sum[0] = dp[i][0];
    // rep(j,1,3001) sum[j] = (sum[j-1] + dp[i][j]) % MOD;
    ll sum = 0;
    rep(j,a[i-1],a[i]) {
      sum += dp[i-1][j];
      sum %= MOD;
    }
    
    rep(j,a[i],b[i]+1){
      sum += dp[i-1][j];
      sum %= MOD;
      dp[i][j] = sum;
    }
    // rep(j,b[n-1]+1) cout << dp[i][j] << ' ';
    // cout << endl;
  }
  ll sum = 0;
  rep(3005) {
    sum += dp[n-1][i];
    sum %= MOD;
  }
  cout << sum << endl;
  //cout << dp[n][b[n-1]] << endl;
  return 0;
}
