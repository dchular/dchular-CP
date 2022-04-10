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
const int MOD = 32768;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void solve(){
  ll a;
  cin >> a;
  if(a == 0) {
    cout << 0 << ' ';
    return;
  }
  ll ans = 15;
  // pattern1 すぐ足す
  chmin(ans,MOD - (a%MOD));
  
  // pattern2 すぐかける
  ll flag = 0;
  ll aa = a;
  if(aa%2 == 1){
    flag++;
    aa++;
  }
  ll cnt = 0;
  while(aa%2 == 0 && aa>0){
    cnt++;
    aa/=2;
  }
  chmin(ans,flag + (15 - cnt));

  // pattern3 2倍してから足す
  cnt = 0;
  cnt += MOD/2 -1  - a%(MOD/2-1);
  cnt += 3;
  chmin(ans,cnt);

  // pattern4 4倍して足す
  cnt = 0;
  cnt += MOD/4-1 - a%(MOD/4-1);
  cnt += 6;
  chmin(ans,cnt);

  // pattern4 8倍して足す
  cnt = 0;
  cnt += MOD/8-1 - a%(MOD/8-1);
  cnt += 11;
  chmin(ans,cnt);

  // pattern5 何回か足してからかける
  rep(15){
    cnt = i;
    aa = a;
    aa += i;
    ll cnt2 = 0;
    while(aa%2 == 0 && aa>0){
      cnt2++;
      aa/=2;
    }
    cnt += 15-cnt2;
    chmin(ans,cnt);
  }

  cout << ans << ' '; 
}

int main(){
  ll testCase;
  cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
