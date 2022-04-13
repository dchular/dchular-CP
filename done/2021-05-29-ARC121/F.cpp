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
  vector<pll> vpx,vpy,v;
  vll ans;
  rep(n){
    ll x,y;
    cin >> x >> y;
    vpx.pb(mp(x,i));
    vpy.pb(mp(y,i));
    v.pb(mp(x,y));
  }
  sort(ALL(vpx));
  sort(ALL(vpy));

  // indexes
  // 大体候補になるインデックス10個ぐらい取る
  vll ins;
  for(int i=0;i<5;i++){
    if(n-1 <= i) continue;
    ins.pb(vpx[i].se);
    ins.pb(vpy[i].se);
  }
  for(ll i=n-1;i>=n-6;i--){
    if(i < 0) break;
    ins.pb(vpx[i].se);
    ins.pb(vpy[i].se);
  }
  // 重複要素消し
  sort(ins.begin(), ins.end());
  ins.erase(std::unique(ins.begin(), ins.end()), ins.end());

  // 取ってきたインデックスで全探索
  rep(i,ins.size()){
    rep(j,i+1,ins.size()){
      ll index1 = ins[i];
      ll index2 = ins[j];
      // ありえないけど、一応チェック
      if(index1 == index2) continue;
      ll xx = abs(v[index1].fi - v[index2].fi);
      ll yy = abs(v[index1].se - v[index2].se);
      ans.pb(max(xx,yy));
    }
  }
  sort(ALL(ans));
  cout << ans[ans.size()-2] << endl;;
  return 0;
}
