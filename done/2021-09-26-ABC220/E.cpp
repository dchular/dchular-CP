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
const ll MAX = 200005;
const int MOD = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vll G[MAX];
ll in[MAX];
ll out[MAX];
ll Rank[MAX];
ll timer = 0;
ll n;

void dfs(ll pos,ll rnk){
  in[pos] = timer++;
  Rank[pos] = rnk;
  for(ll to: G[pos]){
    if(Rank[to] != -1) continue; 
    dfs(to,rnk+1);
  }
  out[pos] = timer++;
}

ll ans[MAX];
ll visited[MAX];
void init(){
  rep(MAX){
    visited[i] = 0;
    Rank[i] = -1;
  }
  return;
}
void solve(ll pos){
  visited[pos] = 1;
  for(ll to: G[pos]){
    if(visited[to] == 1) continue;
    ll child = (out[to] - in[to])/2;
    ll child2 = (out[pos] - in[pos])/2;
    ans[to] = ans[pos] - child + (n - child-2);
    solve(to);
  }
}
int main(){
  cin >> n;
  rep(n-1){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  init();
  dfs(0,0);
  ll sum = 0;
  rep(i,1,n){
    sum += Rank[i];
  }
  ans[0] = sum;
  solve(0);
  rep(n) cout << ans[i] << endl;
  return 0;
}
