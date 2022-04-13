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

//int gcd(int a,int b){return b?gcd(b,a%b):a;}
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

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 200000;
const int MOD = 1e9 + 7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  ll n,C;
  cin >> n >> C;
  vector<pll> vec;
  vec.pb(mp(0,0));
  rep(i,n){
    ll a,b,c;
    cin >> a >> b >> c;
    vec.pb(mp(a,c));
    vec.pb(mp(b+1,c*-1));
  }
  sort(ALL(vec));
  ll now = 0;
  ll ans = 0;
  vec.pb(mp(vec[vec.size()-1].fi + 1,0));
  rep(i,vec.size()-1){
    now += vec[i].se;
    //cout << vec[i].fi << ' ' << vec[i+1].fi << ' ' << now << endl;
    if(vec[i].fi == vec[i+1].fi) continue;
    if(now >= C){
      ans += C * (vec[i+1].fi - vec[i].fi);
      //cout << "+=" << C * (vec[i+1].fi - vec[i].fi) << endl;
    }
    else{
      ans += now * (vec[i+1].fi - vec[i].fi);
      //cout << "2+=" << now * (vec[i+1].fi - vec[i].fi) << ' ' << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
