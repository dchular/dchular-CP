#include <bits/stdc++.h>
//#include <atcoder/lazysegtree>
//#include <atcoder/segtree>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i, a, n) for (int i = n - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pause "read -p 'Press Enter to continue...' var"

using namespace std;
//using namespace atcoder;

template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

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
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const ll INF = numeric_limits<ll>::max() / 4;
const ll MAX = 100005;
const int MOD = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vpll G[1005];

int main(){
  ll n, m, k;
  cin >> n >> m >> k;
  ll a[105] = {0};
  rep(m) cin >> a[i];
  rep(m) a[i]--;
  
  rep(n-1){
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].pb({v,i});
    G[v].pb({u,i});
  }
  ll sum[1005] = {0};
  rep(m-1){
    ll start = a[i];
    ll goal = a[i+1];
    queue<ll> Q;
    ll D[1005];
    rep(j, n) D[j] = -1;
    Q.push(start);
    D[start] = 0;
    while (!Q.empty()){
      ll now = Q.front();Q.pop();
      if(now == goal) break;
      for (pair<ll,ll> to : G[now]){
        if(D[to.fi] != -1) continue;
        D[to.fi] = D[now] + 1;
        Q.push(to.fi);
      }
    }
    ll d = D[goal];
    // sum[start]++;
    while(goal != start){
      for(pair<ll,ll> from: G[goal]){
        if(D[from.fi] == d-1){
          goal = from.fi;
          d = D[from.fi];
          sum[from.se]++;
          break;
        }
      }
    }
  }
  ll s = 0;
  //rep(n) cout << sum[i] << endl;
  rep(n) s += sum[i];
  ll goal = (s+k)/2;
  if((s+k) % 2 == 1 || s+k < 0){
    cout << 0 << endl;
    return 0;
  }
  vector<ll>dp(100001);
	dp[0]=1;
  rep(n-1){
    vector<ll>dp2(100001);
    rep(j,0,100001){
      dp2[j] = dp[j];
    }
    rep(j,0,100001){
      if(j + sum[i] > 100000) break;
      dp2[j + sum[i]] += dp[j];
      dp2[j + sum[i]] %= MOD;
    }
    rep(j,0,100001){
      dp[j] = dp2[j];
    }
  }
  //rep(10) cout << dp[i]<<' ';

	// for(ll i=0;i<n-1;i++)
  //    for(ll x=100000;x>=sum[i];x--)
  //       (dp[x]+=dp[x-sum[i]])%=MOD;
  cout << dp[goal] << endl;
  return 0;
}
