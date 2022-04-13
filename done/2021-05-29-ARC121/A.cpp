#include <bits/stdc++.h>
//#include <atcoder/lazysegtree>
//#include <atcoder/segtree>
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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 200005;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  ll n;
  cin >> n;
  vector< tuple <ll,ll,ll> > ans;
  vector<pll> vpx,vpy;
  rep(n){
    ll x,y;
    cin >> x >> y;
    vpx.pb(mp(x,i));
    vpy.pb(mp(y,i));
  }
  sort(ALL(vpx));
  sort(ALL(vpy));

  ll maxX1 = vpx[vpx.size()-1].fi - vpx[0].fi;
  ll maxY1 = vpy[vpy.size()-1].fi - vpy[0].fi;

  ll maxX2 = vpx[vpx.size()-1].fi - vpx[1].fi;
  ll maxY2 = vpy[vpy.size()-1].fi - vpy[1].fi;
  ll maxX3 = vpx[vpx.size()-2].fi - vpx[0].fi;
  ll maxY3 = vpy[vpy.size()-2].fi - vpy[0].fi;

  ans.pb(make_tuple(maxX1,vpx[vpx.size()-1].se,vpx[0].se));
  ans.pb(make_tuple(maxX2,vpx[vpx.size()-1].se,vpx[1].se));
  ans.pb(make_tuple(maxX2,vpx[vpx.size()-2].se,vpx[0].se));
  ans.pb(make_tuple(maxY1,vpy[vpy.size()-1].se,vpy[0].se));
  ans.pb(make_tuple(maxY2,vpy[vpy.size()-1].se,vpy[1].se));
  ans.pb(make_tuple(maxY2,vpy[vpy.size()-2].se,vpy[0].se));

  sort(ALL(ans));
  ll in11 = get<1> (ans[ans.size()-2]);
  ll in12 = get<2> (ans[ans.size()-2]);
  ll in21 = get<1> (ans[ans.size()-1]);
  ll in22 = get<2> (ans[ans.size()-1]);

  if(max(in11,in12) == max(in21,in22) && min(in11,in12) == min(in21,in22) && ans.size()>2){
    cout << get<0> (ans[ans.size()-3]);
  }
  else cout << get<0> (ans[ans.size()-2]);
  cout << endl;
  return 0;
}
