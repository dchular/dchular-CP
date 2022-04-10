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

int main(){
  ll t;
  cin >> t;
  rep(i1,t){
    ll n,m;
    ll ans = -INF;
    cin >> n >> m;
    vll x,y;
    rep(i2,n){
      ll X,Y;
      cin >> X >> Y;
      x.pb(X);
      y.pb(Y);
    }
    vll b;
    rep(n){
      ll sum = x[i] * y[i];
      if(i == 0) b.pb(sum);
      else b.pb(b[i-1] + sum);
    }
    vll a;
    rep(n){
      ll sum = 0;
      if(i != 0) sum = a[i-1] + b[i-1] * y[i];
      sum += y[i]*(y[i]+1)/2 * x[i];
      chmax(ans,sum);
      // 単調増加から単調減少になった場合、間に答えがある
      if(i != 0 && x[i] < 0 && b[i-1] > 0 && b[i] < 0){
        ll xx = x[i] * -1;
        ll kaisu = b[i-1] / xx;
        kaisu = min(kaisu,y[i]);
        ll sum = a[i-1] + b[i-1] * kaisu;
        sum += kaisu * (kaisu+1)/2 * x[i];
        chmax(ans,sum);
      }
      if(i == 0 && x[i] < 0){
        chmax(ans,x[i]);
      }
      a.pb(sum);
    }
    cout << ans << endl;
  }
  return 0;
}
