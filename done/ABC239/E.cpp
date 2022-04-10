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

vll X;
static ll R[100005];
static vll rankV[100005];
ll rankM = -1;
// static priority_queue<ll, vector <ll>, greater<ll> > Q[100005];
static multiset<ll> Q[100005];

static vector<ll> G[100005];

void dfs(ll cu,ll rank){
  R[cu] = rank;
  rankV[rank].pb(cu);
  chmax(rankM,rank);
  for(ll to: G[cu]){
    if(R[to] != -1) continue;
    dfs(to,rank+1);
  }
  return;
}

int main(){
  ll n,q;
  cin >> n >> q;
  rep(n){
    ll x;
    cin >> x;
    X.pb(x);
    R[i] = -1;
  }
  rep(n-1){
    ll v,k;
    cin >> v >> k;
    v--;k--;
    G[v].pb(k);
    G[k].pb(v);
  }
  dfs(0,1);
  for(ll rank = rankM;rank>0;rank--){
    for(ll cu: rankV[rank]){
      Q[cu].insert(X[cu]);
      for(ll child: G[cu]){
        if(R[child] > R[cu]){
          for(auto it = Q[child].begin();it!=Q[child].end();it++){
            Q[cu].insert(*it);
          }
        }
      }
      while(Q[cu].size()>20){
        auto it = Q[cu].begin();
        Q[cu].erase(it);
      }
      // for(auto it = Q[cu].begin();it!=Q[cu].end();it++){
      //   cout << cu << ' ' << *it << endl;
      // }
    }
  }
  rep(q){
    ll v,k;
    cin >> v >> k;
    v--;
    auto it = Q[v].end();
    rep(j,k) it--;
    cout << *it << endl;
  }
  return 0;
}
