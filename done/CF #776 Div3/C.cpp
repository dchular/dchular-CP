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

void solve(){
  ll n,m;
  cin >> n >> m;
  vector<tuple<ll,ll,ll>> p;
  rep(m){
    ll x,w;
    cin >> x >> w;
    p.pb(make_tuple(w,x,i+1));
  }
  sort(ALL(p));
  vector<tuple<ll,ll,ll>> p2;
  ll ans = 0;
  rep(2*n){
    ll x = get<1>(p[i]);
    ll w = get<0>(p[i]);
    ll j = get<2>(p[i]);
    p2.pb(make_tuple(x,w,j));
    ans += w;
  }
  sort(ALL(p2));
  rep(p2.size()) {
    ll x = get<1>(p2[i]);
    ll w = get<0>(p2[i]);
    ll j = get<2>(p2[i]);
    // cout << x << ' ' << w << ' ' << j << endl;
  }
  cout << ans << endl;
  rep(n){
    ll j1 = get<2>(p2[i]);
    ll j2 = get<2>(p2[2*n-1-i]);
    cout << j1 << ' ' << j2 << endl;
  }
}

int main(){
  ll testCase;
  cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
