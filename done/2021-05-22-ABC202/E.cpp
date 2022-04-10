#include <bits/stdc++.h>
//#define rep(i,a,n) for (int i=a;i<n;i++)
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define rrep(i,a,n) for (int i=n-1;i>=a;i--)
#define ALL(x) x.begin(),x.end()

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pause "read -p 'Press Enter to continue...' var"

using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define in(x,y)(0<=(x)&&(x)<h&&0<=(y)&&(y)<w)

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
const ll MAX = 200005;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll in[MAX];
ll out[MAX];
vll rnkV[MAX];
vll children[MAX];

ll timer = 0;

void dfs(ll pos,ll rnk){
  in[pos] = timer++;
  rnkV[rnk].pb(in[pos]);
  for(ll to: children[pos]){
    dfs(to,rnk+1);
  }
  out[pos] = timer++;
}

int main() {
	ll n;
  cin >> n;
  rep(n-1){
    ll p;
    cin >> p;
    p--;
    children[p].pb(i+1);
  }
  dfs(0,0);
  ll q;
  cin >> q;
  rep(q){
    ll u,d;
    cin >> u >> d;
    u--;
    ll cnt = 0;
    cnt = lower_bound(rnkV[d].begin(),rnkV[d].end(), out[u]) - lower_bound(rnkV[d].begin(),rnkV[d].end(), in[u]);
    cout << cnt << endl;
  }
  return 0;
}
