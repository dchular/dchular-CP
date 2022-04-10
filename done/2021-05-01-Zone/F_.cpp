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
const ll MAX = 200000;
const int MOD = 1e9 + 7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int h,w;
char map[2005][2005];
long long sum[2005][2005] = {0};
long long tmp = 1000000007;

int main(){
  cin >> h >> w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> map[i][j];
    }
  }
  sum[0][0] = 1;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){

      for(int k=j+1;k<w;k++){
        if(map[i][k] == '#') break;
        sum[i][k] += sum[i][j];
        sum[i][k] = sum[i][k] % tmp;
      }

      for(int k=i+1;k<h;k++){
        if(map[k][j] == '#') break;
        sum[k][j] += sum[i][j];
        sum[k][j] = sum[k][j] % tmp;
      }

      int k1 = i+1;
      int k2 = j+1;
      while(1){
        if(k1 >= h || k2 >= w) break;
        if(map[k1][k2] == '#') break;
        sum[k1][k2] += sum[i][j];
        sum[k1][k2] = sum[k1][k2] % tmp;
        k1++;
        k2++;
      }
    }
  }
  cout << sum[h-1][w-1] % tmp;
  return 0;
}
