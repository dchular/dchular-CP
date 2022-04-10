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

ll n,m;
string s[105];
string c[105];

void solve(){
  cin >> n >> m;
  rep(n){
    cin >> s[i];
    c[i] = s[i];
  }
  
  set< pair<pll,pll> > rectangleSet;
  rep(n){
    rep(j,m){
      if(s[i][j] == '1'){
        ll xmx,xmn,ymx,ymn;
        xmx = i;
        xmn = i;
        ymx = j;
        ymn = j;
        while(s[i][ymx+1] == '1' && ymx+1 < m){
          ymx++;
        }
        while(ymn-1 >= 0 && s[i][ymn-1] == '1'){
          ymn--;
        }
        while(xmx +1 < n){
          bool flag = false;
          rep(k,ymn,ymx+1){
            if(s[xmx+1][k] != '1'){
              flag = true;
              break;
            }
          }
          if(flag) break;
          xmx++;
        }
        while(xmn-1 >= 0){
          bool flag = false;
          rep(k,ymn,ymx+1){
            if(s[xmn-1][k] != '1'){
              flag = true;
              break;
            }
          }
          if(flag) break;
          xmn--;
        }
        pair<pll,pll> P = { {xmn,ymn},{xmx,ymx} };
        if(rectangleSet.find(P) == rectangleSet.end()){
          // cout << P.fi.fi << ' ' << P.fi.se << ' ' << P.se.fi << ' ' << P.se.se<< endl;
          // cout << i << j << "x" << endl;
          rectangleSet.insert(P);
          rep(k1,xmn,xmx+1){
            rep(k2,ymn,ymx+1){
              if(c[k1][k2] == '2'){
                cout << "NO\n";
                return;
              }
              c[k1][k2] = '2';
            }
          }
        }

        xmx = i;
        xmn = i;
        ymx = j;
        ymn = j;
        while(s[xmx+1][j] == '1' && xmx+1 < n){
          xmx++;
        }
        while(xmn-1 >= 0 && s[xmn-1][j] == '1'){
          xmn--;
        }
        while(ymx +1 < m){
          bool flag = false;
          rep(k,xmn,xmx+1){
            if(s[k][ymx+1] != '1'){
              flag = true;
              break;
            }
          }
          if(flag) break;
          ymx++;
        }
        while(ymn-1 >= 0){
          bool flag = false;
          rep(k,xmn,xmx+1){
            if(s[k][ymn-1] != '1'){
              flag = true;
              break;
            }
          }
          if(flag) break;
          ymn--;
        }
        
        P = { {xmn,ymn},{xmx,ymx} };
        if(rectangleSet.find(P) == rectangleSet.end()){
          // cout << P.fi.fi << ' ' << P.fi.se << ' ' << P.se.fi << ' ' << P.se.se<< endl;
          // cout << i << j << "y" << endl;
          rectangleSet.insert(P);
          rep(k1,xmn,xmx+1){
            rep(k2,ymn,ymx+1){
              if(c[k1][k2] == '2'){
                cout << "NO\n";
                return;
              }
              c[k1][k2] = '2';
            }
          }
        }
      }
    }
  }
  // for(auto it = rectangleSet.begin();it!=rectangleSet.end();it++){
  //   pair<pll,pll> P;
  //   P = *it;
  //   cout << P.fi.fi << ' ' << P.fi.se << ' ' << P.se.fi << ' ' << P.se.se<< endl;
  // }
  // rep(n) cout << c[i] << endl;
  cout << "YES\n";
  return;
}

int main(){
  ll testCase;
  cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
