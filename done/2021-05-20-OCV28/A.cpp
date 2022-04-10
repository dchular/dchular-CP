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
#define in(x,y)(0<=(x)&&(x)<h&&0<=(y)&&(y)<w)

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

int main(){
  ll n;
  cin >> n;
  ll sum = 0;
  vll x,sortX;
  rep(n){
    ll xInput;
    cin >> xInput;
    x.pb(xInput);
    sortX.pb(xInput);
  }
  sort(ALL(sortX));
  map<ll,ll> indexMap;
  rep(i,n){
    indexMap[sortX[i]] = i;
  }
  // 1 2 3 4
  // 1 -> 3
  // 2 -> 3
  // 3 -> 2
  // 4 -> 2
  // 3 より前か後ろか
  // n/2 <   -> n/2が答え
  // else n/2-1 が答え
  rep(i,n){
    if(indexMap [x[i]] < n/2){
      cout << sortX[n/2] << endl;
    }
    else{
      cout << sortX[n/2-1] << endl;
    }
  }
  return 0;
}
