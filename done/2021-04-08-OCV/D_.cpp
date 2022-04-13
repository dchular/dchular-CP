#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
//#include <bits/stdc++.h>
//#define rep(i,a,n) for (int i=a;i<n;i++)
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define rrep(i,a,n) for (int i=n-1;i>=a;i--)

#define pb push_back
#define mp make_pair
#define fi first
#define se second

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
const ll MAX = 5 * 1e2;
const int MOD = 998244353;

char m[MAX+5][MAX+5];
ll h,w;
bool flag = false;
int visited[MAX+5][MAX+5];
int dx[] = {-1,+1, 0, 0};
int dy[] = { 0, 0,-1,+1};
int si,sj,gi,gj;

void solve(int x,int y){
  if(x == gi && y == gj){
    flag = true;
    return;
  }
  rep(i,4){
    int a,b;
    a = x+dx[i];
    b = y+dy[i];
    if(a >= 0 && a < h && b >=0 && b<w){
      if(m[a][b] == '.' && visited[a][b] < visited[x][y]){
        visited[a][b] = visited[x][y];
        solve(a,b);
      }
      if(m[a][b] == '#' && visited[a][b] < visited[x][y]-1){
        visited[a][b] = visited[x][y]-1;
        solve(a,b);
      }
    }
  }
}

int main(){
  cin >> h >> w;
  rep(i,h){
    rep(j,w){
      cin >> m[i][j];
      visited[i][j] = -1;
      if(m[i][j] == 's'){
        si = i;
        sj = j;
        visited[i][j] = 2;
      }
      if(m[i][j] == 'g'){
        m[i][j] = '.';
        gi = i;
        gj = j;
      }
    }
  }

  solve(si,sj);
  // rep(i,h){
  //   rep(j,w){
  //     cout << visited[i][j];
  //   }cout << endl;
  // }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
