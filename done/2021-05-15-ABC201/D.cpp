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

ll H,W;
ll G[2005][2005] = {0};
ll DP[2005][2005] = {0};

bool isT(int i,int j){ // Takahashi ga fumu, Aoki ga erabu
  if((i+j) % 2 == 1) return true;
  else return false;
}

int main(){
  cin >> H >> W;
  rep(i,H){
    rep(j,W){
      char c;
      cin >> c;
      if(c == '+'){
        if(isT(i,j)) G[i][j] = 1;
        else G[i][j] = -1;
      }
      else{
        if(isT(i,j)) G[i][j] = -1;
        else G[i][j] = 1;
      }
    }
  }
  // rep(i,H){
  //   rep(j,W){
  //     cout << G[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  if(H == 1 && W == 1){
    cout << "Draw" << endl;
    return 0;
  }
  DP[H-1][W-1] = G[H-1][W-1];
  G[0][0] = 0;
  for(int i = H-2;i>=0;i--) DP[i][W-1] = DP[i+1][W-1] + G[i][W-1];
  for(int i = W-2;i>=0;i--) DP[H-1][i] = DP[H-1][i+1] + G[H-1][i];
  for(int i = H-2;i>=0;i--){
    for(int j = W-2;j>=0;j--){
      if(!isT(i,j)){
        DP[i][j] = max(DP[i+1][j],DP[i][j+1]) + G[i][j];
      }
      else{
        DP[i][j] = min(DP[i+1][j],DP[i][j+1]) + G[i][j];
      }
    }
  }
  // rep(i,H){
  //   rep(j,W){
  //     cout << DP[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  if(DP[0][0] == 0) cout << "Draw" << endl;
  else if(DP[0][0] > 0) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
