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

ll pw(ll a,ll b){
  if(b==0) return 1;
  ll ret = 1;
  rep(b) ret*=a;
  return ret;
}

int main(){
  const ll mx = 100000;
  static ll vec[mx] = {0};
  vll vlist;
  vlist.pb(1);
  vlist.pb(2);
  vlist.pb(3);
  
  rep(5){
    for(ll val : vlist){
      if(val < pw(10,i)) continue;
      val *= 10;
      val += 1;
      vlist.pb(val);
      val += 1;
      vlist.pb(val);
      val += 1;
      vlist.pb(val);
    }
  }
  for(ll val : vlist) {
    if(val > mx) continue;
    vec[val] = 1;
  }
  rep(12){
    rep(j,mx){
      if(vec[j] != 0){
        for(ll val : vlist) {
          if(j+val > mx) continue;
          if(vec[j+val] == 0){
            vec[j+val] = vec[j] + 1;
          }
        }
      }
    }
  }
  vec[0] = 4;
  ll t;
  cin >> t;
  rep(t){
    ll n;
    cin >> n;
    n = n%10000;
    cout << vec[n] << endl;
  }
  return 0;
}
