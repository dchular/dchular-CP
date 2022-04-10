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
const ll MAX = 1000'000'000;
const int MOD = 998244353;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll para[3005][5];
ll n;

ll mask(ll i, ll x){
  ll res = 0;
  rep(j,5){
    if(para[i][j] >= x) res += 1 << j;
  }
  return res;
}

bool check(ll x){
  int msk[1 << 5] = {0};
  rep(i,n){
    msk[mask(i,x)]++;
  }
  rep(i,1<<5){
    rep(j,1<<5){
      rep(k,1<<5){
        if((i | j | k) == ((1<<5) - 1) && msk[i] > 0 && msk[j] > 0 && msk[k] > 0 && msk[i] + msk[j] + msk[k] >= 3){
          return true;
        }
      }
    }
  }
  return false;
}

int main(){
  cin >> n;
  rep(i,n){
    rep(j,5){
      cin >> para[i][j];
    }
  }
  ll right = INF;
  ll left = 0;
  while((left + 1) != right){
    ll md = (right + left) / 2;
    if(check(md)) left = md;
    else right = md;
  }
  cout << left;
  return 0;
}
