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

ll n;
ll a[501];
bool f = false;
vll v;

void swap(int i){
  ll t = a[i];
  a[i] = a[i+1];
  a[i+1] = t;
}

bool check(){
  if(f) return true;
  f = true;
  for(int i=0;i<n;i++){
    if(a[i] != i+1) f = false;
  }
  if(f){
    cout << v.size() << endl;
    rep(i,v.size()) cout << v[i] << ' ';
    cout << endl;
  }
  return f;
}

void dfs(int now){
  // now -> 0 or 1
  if (check()) return;
  for(int i=now;i<n;i+=2){
    if(a[i] > i+1){
      swap(i);
      v.pb(i+1);
      if(now == 0) dfs(1);
      else dfs(0);
      v.pop_back();
      swap(i+1);
    }
  }
}

int main(){
  ll t;
  cin >> t;
  rep(t){
    cin >> n;
    rep(j,n) cin >> a[j];
    dfs(1);
  }
  return 0;
}
