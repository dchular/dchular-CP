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

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 200005;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll k,n,m;
ll a[100005];
#define double long double
bool check(ll x){
  ll l = 0;
  ll r = 0;
  rep(i,k){
    ll l1 = (m*a[i] - x + n - 1) / n;
    ll r1 = (m*a[i] + x) / n;
    if(l1 <= 0) l1 = 0;
    l += l1;
    r += r1;
  }
  if(l <= m && r >= m) return true;
  else return false;
}

void print(ll x){
  ll sum = 0;
  rep(i,k){
    ll l = (m*a[i] - x + n - 1) / n;
    if(l<=0) l = 0;
    sum += l;
  }
  sum = m - sum;
  rep(i,k){
    ll l = (m*a[i] - x + n - 1) / n;
    ll r = (m*a[i] + x) / n;
    if(l <= 0) l = 0;
    if(sum == 0){
      cout << l << ' ';
    }
    else if(sum >= (r-l)){
      cout << r << ' ';
      sum -= (r-l);
    }
    else{
      cout << l + sum << ' ';
      sum = 0;
    }
  }
}

int main(){
  cin >> k >> n >> m;
  rep(i,k) cin >> a[i];
  ll ng = -1;
  ll ok = INF;
  //rep(i,10) cout << check(i);
  while(ok - ng > 1){
    ll mid = (ok+ng)/2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  // cout << ng << endl;
  print(ok);
  return 0;
}
