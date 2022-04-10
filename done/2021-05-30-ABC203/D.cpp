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

ll n,k;
ll A[805][805];
ll bA[805][805];

bool check(ll lim){
  rep(i,1,n+1){
    rep(j,1,n+1){
      if(A[i][j] >= lim) bA[i][j] = 1;
      else bA[i][j] = 0;
    }
  }
  rep(i,n+1){
    rep(j,2,n+1){
      bA[i][j] += bA[i][j-1];
    }
  }
  rep(i,2,n+1){
    rep(j,1,n+1){
      bA[i][j] += bA[i-1][j];
    }
  }
  ll goal = k*k/2 + 1;
  rep(i,k,n+1){
    rep(j,k,n+1){
      ll youso = bA[i][j] - bA[i-k][j] - bA[i][j-k] + bA[i-k][j-k];
      if(youso < goal) return false;
    }
  }
  return true;
  // i,j までに >= lim な要素の数
  // i,j - i,j-k - i-k,j + i-k,j-k
  // 1 2 3 4
  // 5 6 7 8
  // 9 9 9 9
  // 0 1 0
  // 1 0 1
  // 1 1 1

  // 0 1 1
  // 1 1 2
  // 1 2 3

  // 0 1 1
  // 1 2 3
  // 2 4 6
}

int main(){
  cin >> n >> k;

  rep(i,1,n+1){
    rep(j,1,n+1){
      cin >> A[i][j];
    }
  }

  ll ok = 0, ng = INF;
  // ok ok ng ng
  while(ok+1 != ng){
    ll md = (ok + ng) / 2;
    if(check(md)) ok = md;
    else ng = md;
  }
  cout << ok << endl;
  return 0;
}
