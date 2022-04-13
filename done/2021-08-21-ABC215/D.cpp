#include <bits/stdc++.h>
//#include <atcoder/dsu>
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
typedef vector<pair<ll,ll>> vpll;

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 200005;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

set<ll> prime;
vll tmp;
static ll pWork[100001] = {0};
ll n,m;

void rec(ll now){
  if(pWork[now] == 0){
    pWork[now]++;
    tmp.pb(now);
    //cout << now << "aa";
  }
  for(auto it = prime.begin(); it!= prime.end();it++){
    ll val = *it;
    if(val * now > m) break;
    if(pWork[val*now] == 0) {
      // cout << val*now << "aaa" << endl;
      rec(val*now);
    }
  }
  return;
}

int main() {
	cin >> n >> m;
  vll a(n);
  rep(i,2,m+1){
    if(pWork[i] == 0){
      prime.insert(i);
      for(ll j = 2;j*i <= m+1; j++){
        pWork[j*i] = 1;
      }
    }
  }
  static ll pWork2[100001] = {0};
  rep(n){
    cin >> a[i];
    for(auto it = prime.begin(); it!= prime.end();){
      ll val = *it;
      if(*it > 1000) break;
      if(a[i] % *it == 0){
        it = prime.erase(it);
        for(ll j = 1;j*val <= m;j++){
          pWork2[j*val] = 1;
          //cout << j*val << "AA\n";
        }
      }
      else{
        ++it;
      }
    }

    if(prime.find(a[i]) != prime.end()){
      pWork[a[i]] = 1;
      prime.erase(a[i]);
      if(a[i] != 1)
      for(ll j = 1;j*a[i] <= m;j++){
          pWork2[j*a[i]] = 1;
          //cout << j*a[i]
          //cout << j*val << "AA\n";
      }
      continue;
    }
  }
  ll ans = 0;
  rep(i,1,m+1){
    if(pWork2[i] == 0) ans++;
  }
  cout << ans << endl;
  rep(i,1,m+1){
    if(pWork2[i] == 0) cout << i << endl;
  }
  
  return 0;
  // rep(100001) pWork[i] = 0;
  // for(auto it = prime.begin(); it!= prime.end();it++) {
  //   pWork[*it]++;
  // }
  
  // // cout << prime.size() + 1 << endl << 1 << endl;;
  // for(auto it = prime.begin(); it!= prime.end();it++)
  //   rec(*it);
  // rep(tmp.size()) {
  //   prime.insert(tmp[i]);
  // }
  // prime.insert(1);
  // cout << prime.size() << endl;
  // for(auto it = prime.begin(); it!= prime.end();it++) cout << *it << endl;
  // return 0;
}
