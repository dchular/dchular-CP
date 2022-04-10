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

ll par[MAX];
//ll rnk[MAX];
vll pars[MAX];
//map<ll,ll> pars[MAX];
vll rnks[MAX];
bool visited[MAX];
ll r = 0;
map<ll,ll> ansMap[MAX]; // d u

void dfs2(ll start,ll pos){
  ll parent = par[pos];
  if(start == pos) r = 0;
  r++;
  if(visited[parent]){
    rnk[start] = r + rnk[parent];
    rnks[rnk[start]].pb(start);
    ll ra = rnk[start];
    // rep(i,pars[parent].size()){
    //   pars[start].pb(pars[parent][i]);
    //   ansMap[ra][pars[parent][i]]++;
    // }
    // for(auto itr = pars[parent].begin(); itr != pars[parent].end(); ++itr) {
    //   ll val = itr -> first;
    //   pars[start][val] ++;
    //   ansMap[ra][val] ++;
    // }
    //ansMap[ra][start]++;
    visited[start] = true;
    return;
  }
  else{
    pars[start].pb(pos);
    //pars[start][pos]++;
    dfs2(start,parent);
  }
  return ;
}

void dfs(ll pos,ll rnk){
  
}

int main() {
	ll n;
  cin >> n;
  rep(n+1) {
    visited[i] = false;
    pars[i].pb(i);
    //pars[i][i]++;
  }
  ansMap[0][1] = 1;
  visited[1] = true;
  rnks[0].pb(1);
  rep(n-1){
    ll p;
    cin >> p;
    par[i+2] = p;
  }
  dfs(1);
  // rep(i,n+1){
  //   cout << i << ':' << endl;
  //   cout << "rank:" << rnk[i] << endl;
  //   cout << "parents:" << ' ';
  //   rep(j,pars[i].size()){
  //     cout << pars[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // rep(i,4){
  //   cout << i << ":" << endl;
  //   for(auto itr = ansMap[i].begin(); itr != ansMap[i].end(); ++itr) {
  //     cout << itr -> fi << ' ' << itr -> se << endl;
  //   }
  //   cout << endl;
  // }
  ll q;
  cin >> q;
  rep(q){
    ll u,d;
    cin >> u >> d;
    ll cnt = 0;
    if(ansMap[d][u] != 0) cnt+=ansMap[d][u];
    // rep(j,rnks[d].size()){
    //   ll val = rnks[d][j];
    //   ll flag = 0;
    //   // rep(k,pars[val].size()){
    //   //   if(pars[val][k] == u){
    //   //     flag = 1;
    //   //     break;
    //   //   }
    //   // }
    //   if(pars[val][u] != 0) cnt++;
    //   //cnt += flag;
    // }
    cout << cnt << endl;
  }
  return 0;
}
