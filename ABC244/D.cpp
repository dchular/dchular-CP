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
  ll n,m;
  cin >> n >> m;
  vll a(n+1),b(m+1),c(n+m+1);
  rep(n+1) cin >> a[i];
  rep(m+1) b[i] = -INF;
  rep(n+m+1) cin >> c[i];
  vector<bool> bf(m+1);
  vector<bool> cf(n+m+1);
  rep(m+1) bf[i] = false;
  rep(n+m+1) cf[i] = false;

  while(1){
    bool endFlag = true;
    rep(m+1){
      if(b[i] == -INF) endFlag = false;
    }
    if(endFlag) break;
    
    endFlag = true;
    rep(n+m+1){
      if(cf[i] == false) endFlag = false;
    }
    if(endFlag){
      rep(m+1) if(b[i] == -INF) b[i] = 0;
      break;
    }

    endFlag = true;
    rep(n+m+1){
      if(cf[i] == true) continue;
      ll sum = c[i];
      ll sumTmp = 0; // 特定出来るb?以外の合計
      ll index = -1;// 特定出来るb?を見つけたループのインデックス
      rep(j,i+1){// aj*b[i-j]
        if(j > n) continue;
        if(i-j > m) continue;
        if(a[j] == 0) continue;
        if(b[i-j] == -INF){
          if(index != -1) {
            index = -1;
            break;
          }
          index = j;
        }
        else{
          sumTmp += a[j] * b[i-j];
        }
      }
      if(index < 0) continue;
      b[i-index] = (sum - sumTmp) / a[index];
      endFlag = false;
      cf[i] = true;
    }
    if(endFlag){
      rep(m+1) if(b[i] == -INF) b[i] = 0;
      break;
    }
  }
  rep(m+1) cout << b[i] << ' ';
  cout << endl;
  return 0;
}
