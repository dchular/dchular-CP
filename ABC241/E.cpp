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

bool visited[200005];

int main(){
  ll n,k;
  cin >> n >> k;
  vll a(n);
  rep(n) cin >> a[i];
  rep(n) visited[i] = false;
  ll ans = 0;
  ll loop = -1;
  ll loopIn = -1;
  ll loopCnt = 0;
  ll loopSum = 0;
  rep(i,1,k+1){
    // second loop begin
    if(loopIn == ans%n){
      ll nokori = k+1 - i;
      ll loopNokori = nokori / loopCnt;
      // i += loopNokori * loopCnt;
      ans += loopSum * loopNokori;
      rep(nokori % loopCnt){
        ans += a[ans%n];
      }
      cout << ans << endl;
      return 0;
    }
    // first loop begin
    if(visited[ans%n] && loop == -1){
      loop = 1;
      loopIn = ans%n;
      loopCnt = 0;
      loopSum = 0;
    }
    visited[ans%n] = true;
    ans += a[ans%n];
    if(loop) {
      loopSum += a[ans%n];
      loopCnt ++;
    }
  }
  cout << ans << endl;
  return 0;
}
