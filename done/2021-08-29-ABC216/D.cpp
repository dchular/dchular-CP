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

vector< stack<ll> > vs;
static pll memo[200005];
ll n,m;

void solve(ll i1, ll val);

void check(ll i){
  //cout << "CHEKING:" << i << endl; 
  if(vs[i].empty()) return;
  memo[vs[i].top()].fi ++;
  if(memo[vs[i].top()].fi == 1)
    memo[vs[i].top()].se = i;
  if(memo[vs[i].top()].fi == 2)
    solve(i,vs[i].top());
  return;
}

void solve(ll i1, ll val){
  //cout << "SOLVE\n";
  ll i2 = memo[val].se;
  //cout << "i1 = " << i1 << " i2 = "  << i2 << ' ' << val << endl;
  vs[i1].pop();
  //cout << "POP1 SUCCEED:" << i1 << endl;
  check(i1);
  //cout << "CHECK1 SUCCEED:" << i1 << endl;
  vs[i2].pop();
  //cout << "POP2 SUCCEED:" << i2 << endl;
  check(i2);
  //cout << "CHECK2 SUCCEED:" << i2 << endl;
}

int main(){
  cin >> n >> m;
  rep(m){
    ll k;
    cin >> k;
    stack<ll> s;
    rep(j,k){
      ll a;
      cin >> a;
      s.push(a);
    }
    vs.pb(s);
    check(i);
  }
  rep(m){
    if(vs[i].size() != 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
