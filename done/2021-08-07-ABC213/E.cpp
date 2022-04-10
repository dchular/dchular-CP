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
const int MOD = 998244353;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

const int n_max = 5005;
vll G[n_max];
ll h,w;
string s[505];
ll ans[505][505];
void bfs(ll a,ll b){
  queue<pll> Q;
  Q.push(mp(a,b));
  while (!Q.empty()) {
		pll pos = Q.front(); Q.pop();
    ll x = pos.fi;
    ll y = pos.se;
    ll step = ans[x][y];
    rep(4){
      ll xx = dx[i] + x;
      ll yy = dy[i] + y;
      if(xx >= 0 && xx < h && yy>=0 && yy < w){
        if(s[xx][yy] == '.' && ans[xx][yy] > step){
          ans[xx][yy] = step;
          Q.push(mp(xx,yy));
        }
      }
    }
  }
}

ll dxx[4] = {0,1,0,1};
ll dyy[4] = {0,0,1,1};

void punch(ll x, ll y){
  ll minV = INF;
  rep(j,4){
    ll xxx = x+dxx[j];
    ll yyy = y+dyy[j];
    if(s[xxx][yyy] == '#'){
      rep(4){
        ll xx = dx[i] + x;
        ll yy = dy[i] + y;
        if(xx >= 0 && xx < h && yy>=0 && yy < w){
          if(ans[xxx][yyy] > ans[xx][yy] + 1){
            ans[xxx][yyy] = ans[xx][yy] + 1;
            chmin(minV,ans[xxx][yyy]);
          }
        }
      }
      chmin(minV,ans[xxx][yyy]+1);
    }
    else chmin(minV,ans[xxx][yyy] + 1);
  }

  rep(j,4){
    ll xxx = x+dxx[j];
    ll yyy = y+dyy[j];
    chmin(ans[xxx][yyy],minV);
    bfs(xxx,yyy);
  }
}

int main(){
  cin >> h >> w;
  rep(h) cin >> s[i];
  rep(h){
    rep(j,w){
      ans[i][j] = INF;
    }
  }
  ans[0][0] = 0;
  bfs(0,0);
  rep(h-1){
    rep(j,w-1){
      punch(i,j);
    }
  }
  // rep(h){
  //   rep(j,w){
  //     cout << ans[i][j] << ' ';
  //   }cout << endl;
  // }
  cout << ans[h-1][w-1] << endl;
  return 0;
}
