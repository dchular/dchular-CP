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

int main(){
  ll n,in;
  cin >> n;
  vll va,vb,vc;
  vector<pair<ll,char>> v;
  rep(n){
    cin >> in;
    v.pb(mp(in,'a'));
  }
  rep(n){
    cin >> in;
    v.pb(mp(in,'b'));
  }
  rep(n){
    cin >> in;
    v.pb(mp(in,'c'));
  }
  sort(ALL(v));
  ll a = 0,b = 0,c = 0;
  ll A = INF,B = INF,C = INF;
  ll aMx = -1,bMx = -1;
  rep(n*3){
    char ch = v[i].se;
    ll val = v[i].fi;
    if(ch == 'a') {
      a++;
      if(A == val){
        aMx++;
      }
      else{
        A = val;
        aMx = 1;
      }
    }
    if(ch == 'b' && a>0){
      bool flag = false;
      if(A != val){
        flag = true;
      }
      else{// Amax == bNow
        if(aMx != a)
          flag = true;
      }
      if(flag){
        b++;a--;
        if(B == val){
          bMx++;
        }
        else{
          B = val;
          bMx = 1;
        }
      }
    }
    if(ch == 'c' && b>0){
      bool flag = false;
      if(B != val){
        flag = true;
      }
      else{// Bmax == cNow
        if(bMx != b)
          flag = true;
      }
      if(flag){
        c++;b--;
      }
    }
  }
  cout << c;
  return 0;
}
