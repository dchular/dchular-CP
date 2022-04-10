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

ll mn(ll a,ll b,ll c){
  return min(min(a,b),c);
}

void solve(){
  ll C[3],M[3],Y[3],K[3];
  rep(3) cin >> C[i] >> M[i] >> Y[i] >> K[i];
  ll c = mn(C[0],C[1],C[2]);
  ll m = mn(M[0],M[1],M[2]);
  ll y = mn(Y[0],Y[1],Y[2]);
  ll k = mn(K[0],K[1],K[2]);
  ll goal = 1000000;
  if(c + m + y + k >= goal){
    ll goal2 = (c+m+y+k) - goal;
    if(goal2 > c){
      goal2 -= c-1;
      c = 1;
      if(goal2 > m){
        goal2 -= m-1;
        m = 1;
        if(goal2 > y){
          goal2 -= y-1;
          y = 1;
          if(goal2 > k){
            goal2 -= k-1;
            k = 1;
          }
          else k-=goal2;
        }
        else y -= goal2;
      }
      else m -= goal2;
    }
    else {
      c -= goal2;
    }
    cout << c << ' ' << m << ' ' << y << ' ' << k<< endl;
  }
  else cout  << "IMPOSSIBLE" << endl;
}

int main(){
  ll T;
  cin >> T;
  rep(T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
