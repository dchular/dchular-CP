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

ll n,k;
ll dis(ll i){
  ll ret = 0;
  if(i < k){
    return k - 1 - i;
  }
  else{
    return i - k;
  }
}

int main(){
  cin >> n >> k;
  vll A(n);
  rep(n) cin >> A[i];
  vector<pll> vk,vnotK;
  rep(n){
    if(i < k) vk.pb({A[i],i});
    else vnotK.pb({A[i],i});
  }
  sort(ALL(vk));
  sort(ALL(vnotK));

  ll i1 = vk.size()-1;
  ll i2 = vnotK.size()-1;

  ll dis1 = INF;
  ll dis2 = INF;
  ll ans = INF;
  for(ll i1 = vk.size()-1; i1>=0; i1--){
    ll now = vk[i1].fi;
    ll flag = 1;
    while(now < vnotK[i2].fi && i2 >= 0){
      flag = 0;
      chmin(dis2,dis(vnotK[i2].se));
      i2--;
    }
    if(flag == 0) i2++;
    if(now < vnotK[i2].fi){
      chmin(ans,dis(vk[i1].se) + dis2);
    }
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans+1 << endl;

  return 0;
}
