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
  ll n,C;
  cin >> n >> C;
  vpll v1;
  vpll v2;
  rep(n){
    ll c,d,h;
    cin >> c >> d >> h;
    v1.pb({d*h,c});
    v2.pb({d*h,c});
  }
  auto myComp = [&](pair<ll,ll> e1, pair<ll,ll> e2) {
    return e1.fi > e2.fi;
    };
  sort(ALL(v1),myComp);
  sort(v2.begin(),v2.end(),[](pll l1,pll l2) {return l1.fi * l2.se > l2.fi*l1.se;});
  // rep(v2.size()) cout << v2[i].fi << ' ' << v2[i].se << endl;
  ll m;
  cin >> m;
  rep(m){
    ll d,h;
    cin >> d >> h;
    pll canditate = v2[0];
    ll ans = -1;
    if(canditate.fi != 0 && (d*h / canditate.fi + 1) * canditate.se <= C){
      ans = (d*h / canditate.fi + 1) * canditate.se;
    }

    ll N1 = 0;
    if(canditate.fi != 0 && d * h / canditate.fi != 0)
      N1 = d*h / (d * h / canditate.fi);
    ll N2 = 0;
    if(canditate.fi != 0 && d * h / canditate.fi != 0)
      N2 = d*h / (d * h / canditate.fi)+2;

    

    pll p = mp(N1,0);
    auto it1 = lower_bound(ALL(v1),p,myComp);
    canditate = *it1;
    if(canditate.fi != 0 && (d*h / canditate.fi + 1) * canditate.se <= C){
      ll tmp = (d*h / canditate.fi + 1) * canditate.se;
      if(ans > tmp) ans = tmp;
    }
    
    auto it2 = upper_bound(ALL(v1),p,myComp);
    canditate = *it2;
    if(canditate.fi  != 0 && (d*h / canditate.fi + 1) * canditate.se <= C){
      ll tmp = (d*h / canditate.fi + 1) * canditate.se;
      if(ans > tmp) ans = tmp;
    }
    
    p = mp(N2,0);
    auto it3 = lower_bound(ALL(v1),p,myComp);
    canditate = *it3;
    if(canditate.fi  != 0 && (d*h / canditate.fi + 1) * canditate.se <= C){
      ll tmp = (d*h / canditate.fi + 1) * canditate.se;
      if(ans > tmp) ans = tmp;
    }
    
    auto it4 = lower_bound(ALL(v1),p,myComp);
    canditate = *it4;
    if(canditate.fi != 0 && (d*h / canditate.fi + 1) * canditate.se <= C){
      ll tmp = (d*h / canditate.fi + 1) * canditate.se;
      if(ans > tmp) ans = tmp;
    }
    
    cout << ans << endl;
  }
}

int main(){
  ll testCase = 1;
  // cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
