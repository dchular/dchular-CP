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

const int n_max = 405;
vector<pll> G[n_max];
vpll G2[n_max];
ll dis[n_max];
void init(){
  rep(i,n_max) dis[i] = INF;
  return;
}

void dijkstra(ll start,ll k){
  init();
  dis[start] = 0;
  priority_queue<pll, vector <pll>, greater<pll> > Q;
  Q.push(mp(0,start));
  while(!Q.empty()){
    pll P = Q.top();Q.pop();
    ll now = P.se;
    rep(i,G[now].size()){
      ll to = G[now][i].fi;
      ll cost = G[now][i].se;
      if(cost + dis[now] < dis[to] && (to <= k || to == start) ){
        dis[to] = cost + dis[now];
        Q.push(mp(dis[to],to));
      }
      if(cost + dis[now] < dis[to] && (to > k)){
        dis[to] = cost + dis[now];
      }
    }
  }
}


int main(){
  ll n,m;
  cin >> n >> m;
  rep(m){
    ll a,b,c;
    cin >> a >> b >> c;
    G[a].pb(mp(b,c));
    G2[b].pb(mp(a,c));
  }
  ll ans = 0;
  for(ll i = n;i >= 1;i--){
    rep(k,1,n+1){
      //if(k == 1)
      dijkstra(i,k);
      //else dijkstra2(i,k);
      rep(j,1,n+1){
        if (dis[j] != INF && dis[j] != 0) {
        //  cout << i << ' ' << j << ' ' << k <<' ' <<dis[j] << endl;
          ans += dis[j];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
