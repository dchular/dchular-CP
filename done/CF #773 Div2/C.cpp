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
  ll n,x;
  cin >> n >> x;
  multiset <ll> a;
  map <ll,ll> m;
  rep(n){
    ll in;
    cin >> in;
    a.insert(in);
    m[in] ++;
  }
  ll cnt = 0;
  
  for(auto it = a.begin(); it!= a.end(); it++){
    ll p = *it;
    if(m[p] <= 0) continue;
    auto it2 = a.find(p * x);
    if(it2 != a.end()){
      if(m[*it2] > 0){
        // cout << p << ' ' << *it2;
        m[p]--;
        m[*it2]--;
        // cout << ' ' << m[p] << ' ' << m[*it2] << endl;
        cnt+=2;
      }
      // auto count = a.count(p.fi * x);
      // for(auto i = 0; i < count; ++i){
      //   pll p2 = *it2;
      //   if(p2.se == 0){
      //     p2.se = 1;
      //     p.se = 1;
      //     cnt+=2;
      //     break;
      //   }
      //   ++it2;
      // }
    }
  }
  cout << n-cnt << endl;
  // cout << "-------\n";
}

int main(){
  ll testCase;
  cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
