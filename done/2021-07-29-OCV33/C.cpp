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

deque <pll> de;
// Last in First out
ll stSize = 0,l=0;
bool endF = false;

void pu(){
  ll n,m;
  cin >> n >> m;
  if(stSize + n > l){
    cout << "FULL\n";
    endF = true;
    return;
  }
  stSize += n;
  de.push_back(mp(m,n));
}

void po(){
  ll n;
  cin >> n;
  if(stSize - n < 0){
    cout << "EMPTY\n";
    endF = true;
    return;
  }
  stSize -= n;
  while(n > 0){
    // if(de.empty()) {
    //   cout << "EMPTY\n";
    //   endF = true;
    //   return;
    // }
    pll P = de.back();de.pop_back();
    ll tmp = n;
    n -= P.se;
    P.se -= tmp;
    if(P.se > 0){
      de.push_back(P);
    }
  }
}

void to(){
  if(stSize < 1) {
    cout << "EMPTY\n";
    endF = true;
    return;
  }
  // if(de.empty()) {
  //   cout << "EMPTY\n";
  //   endF = true;
  //   return;
  // }
  cout << de.back().fi << endl;
}

void si(){
  cout << stSize << endl;
}

void check(){
  rep(de.size()){
    cout << de[i].fi << ' ' << de[i].se << ' ';
  }
  cout << "\nSize = " << stSize << endl;
  return;
}

int main(){
  ll q;
  cin >> q >> l;
  rep(q){
    string s;
    cin >> s;
    if(s == "Push") pu();
    if(s == "Pop")  po();
    if(s == "Top")  to();
    if(s == "Size") si();
    //check();
    if(endF){return 0;}
  }
  cout << "SAFE\n";
  return 0;
}
