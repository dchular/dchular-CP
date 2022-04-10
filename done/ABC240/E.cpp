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

static vll G[200005];
static pll lr[200005];
ll inc = 1;
bool visited[200005];

void dfs(ll cu){
  visited[cu] = true;
  ll l = +INF;
  ll r = -INF;
  for(ll to: G[cu]){
    if(visited[to]) continue;
    dfs(to);
    chmin(l,lr[to].fi);
    chmax(r,lr[to].fi);
    chmin(l,lr[to].se);
    chmax(r,lr[to].se);
  }
  if(l == INF && r == -INF) {
    lr[cu] = {inc,inc};
    inc++;
  }
  else lr[cu] = {l,r};
  return;
}

int main(){
  ll n;
  cin >> n;
  rep(n-1){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs(0);
  rep(n){
    cout << lr[i].fi << ' ' << lr[i].se << endl;
  }
  return 0;
}
