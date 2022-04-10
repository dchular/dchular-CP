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

const int n_max = 100005;
vector<ll> G[n_max];

int main(){
  ll m;
  cin >> m;
  rep(m){
    ll u,v;
    cin >> u >> v;;
    G[u].pb(v);
    G[u].pb(v);
  }
  string s="";
  rep(8){
    char c;
    cin >> c;
    s+=c;
  }
  map<string,ll> mp;
  mp[s] = 0;
  string ans = "12345678";

  priority_queue<pair<ll,string>, vector <pair<ll,string>>, greater<pair<ll,string>> > Q;
  Q.push({0,s});
  while(!Q.empty()){
    pair<ll,string> P;
    P = Q.top();Q.pop();
    string now = P.se;
    ll nowNum;
    ll piece[10] = {0};
    ll tmp[10] = {0};
    ll piece2[10] = {0};
    // 1 2 3 4 5 6 7 8
    // 
    rep(now.size()){
      piece[i] = now[i] - '0';
      piece2[now[i] - '0'] = i;
      tmp[now[i] - '0']++;
    }
    // piece コマiがどこか
    // piece2 頂点iがどこか
    rep(i,0,10){
      if(tmp[i] == 0) nowNum = i;
    }
    piece2[nowNum] = -1;
    for(ll to:G[nowNum]){
      char tmp = now[to];
      now[to] = nowNum + '0';
      if(mp.count(now) == 0){
        mp[now] = P.fi+1;
        Q.push({P.fi+1,now});
      }
      now[to] = tmp;
    }
  }
  if(mp.count(ans) == 0) cout << "-1\n";
  else cout << mp[ans] << endl;
  return 0;
}
