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

inline double t_sqrtD( const double &x)
{
  double         xHalf = 0.5 * x;
long long int  tmp   = 0x5FE6EB50C7B537AAl - ( *(long long int*)&x >> 1);//initial guess
double         xRes  = * (double*)&tmp;

xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );
//xRes *= ( 1.5 - ( xHalf * xRes * xRes ) );//コメントアウトを外すと精度が上がる
return xRes * x;
}

struct city{
  ll b;
  ll c;
  ll d;
};

const int n_max = 100005;
vector<city> G[n_max];
ll dis[n_max];

void init(){
  rep(i,n_max) dis[i] = INF;
  return;
}

void dijkstra(ll start){
  init();
  dis[start] = 0;
  priority_queue<pll, vector <pll>, greater<pll> > Q;
  Q.push(mp(0,start));
  while(!Q.empty()){
    pll P = Q.top();Q.pop();
    ll now = P.se;
    ll t = P.fi;
    if(dis[now] < t) continue;
    rep(i,G[now].size()){
      ll to = G[now][i].b;
      if(dis[now] + G[now][i].c > dis[to]){
        continue;
      }
      ll aTime = t + G[now][i].c + G[now][i].d / (t+1); // aTime 着く時間
      if(t*t < G[now][i].d+5){
        // ll l = 0,r=G[now][i].d;
        // while(r>l+1){
        //   ll md = (l+r)/2;
        //   if(md*md > G[now][i].d) r = md;
        //   else l = md;
        // }
        //ll idealTime = l;
        ll idealTime = floor(sqrt(G[now][i].d));
        if(idealTime+3 > t){
          for(ll j = idealTime-3;j<= idealTime + 3;j++){
            if(j<t) continue;
            chmin(aTime,j + G[now][i].c + G[now][i].d / (j+1));
          }
        }
      }
      if(aTime < dis[to]){
        dis[to] = aTime;
        Q.push(mp(dis[to],to));
      }
    }
  }
}

int main(){
  ll n,m;
  cin >> n >> m;
  rep(m){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    a--;b--;
    G[a].pb({b,c,d});
    G[b].pb({a,c,d});
  }
  dijkstra(0);
  if(dis[n-1] == INF){
    cout << -1 << endl;
  }
  else cout << dis[n-1] << endl;
  return 0;
}
