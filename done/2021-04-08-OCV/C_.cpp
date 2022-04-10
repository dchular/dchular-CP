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
int colorMap[MAX+5][MAX+5] = {0};
int colorConnectMap[MAX*MAX+5][MAX*MAX+5] = {0};
int colorCnt = 0;
int si,sj,gi,gj;
int dx[] = {-1,+1, 0, 0};
int dy[] = { 0, 0,-1,+1};
int dx1[] = {-2,+2, 0, 0,+1,+1,-1,-1};
int dy1[] = { 0, 0,-2,+2,+1,-1,+1,-1};
int dx2[] = {-2,-1,+1,+2,-2,-1,+1,+2,-3,+3,0,0};
int dy2[] = {+1,+2,+2,+1,-1,-2,-2,-1,0,0,+3,-3};

void coloring(int x,int y){
  if(colorMap[x][y] != -1) return;
  if(m[x][y] == '#') return;
  colorMap[x][y] = colorCnt;
  rep(i,4){
    int a,b;
    a = x+dx[i];
    b = y+dy[i];
    if(a >= 0 && a < h && b >=0 && b<w){
      coloring(a,b);
    }
  }
}

void twoStep(){
  rep(x,h){
    rep(y,w){
      rep(i,12){
        int a,b;
        a = x+dx2[i];
        b = y+dy2[i];
        if(a >= 0 && a < h && b >=0 && b<w){
          if(m[x][y] != '#' && m[a][b] != '#' && colorMap[a][b] != colorMap[x][y]){
            int aa = colorMap[a][b];
            int bb = colorMap[x][y];
            colorConnectMap[aa][bb] = 2;
            colorConnectMap[bb][aa] = 2;
            //cout << aa << endl << bb << endl << endl;
          }
        }
      }
    }
  }
  if(colorConnectMap[colorMap[si][sj]][colorMap[gi][gj]] == 2)
    flag = true;
  return;
}

void oneStep(){
  rep(x,h){
    rep(y,w){
      rep(i,8){
        int a,b;
        a = x+dx1[i];
        b = y+dy1[i];
        if(a >= 0 && a < h && b >=0 && b<w){
          if(m[x][y] != '#' && m[a][b] != '#' && colorMap[a][b] != colorMap[x][y]){
            int aa = colorMap[a][b];
            int bb = colorMap[x][y];
            colorConnectMap[aa][bb] = 1;
            colorConnectMap[bb][aa] = 1;
            //cout << aa << endl << bb << endl << endl;
          }
        }
      }
    }
  }
  int sc = colorMap[si][sj];
  int gc = colorMap[gi][gj];
  rep(x,colorCnt+1){
    if(colorConnectMap[sc][x] == 1 && colorConnectMap[gc][x] == 1)
      flag = true;
  }
  if(sc == gc) flag = true;
  return;
}

int main(){
  cin >> h >> w;
  rep(i,h){
    rep(j,w){
      cin >> m[i][j];
      if(m[i][j] == 's'){
        si = i;
        sj = j;
      }
      if(m[i][j] == 'g'){
        gi = i;
        gj = j;
      }
      colorMap[i][j] = -1;
    }
  }
  rep(i,h){
    rep(j,w){
      if(colorMap[i][j] != -1) continue;
      if(m[i][j] == '#') continue;
      coloring(i,j);
      colorCnt++;
    }
  }
  twoStep();
  oneStep();

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
