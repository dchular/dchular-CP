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

bool visited[2005];
ll n;
vll a,b,ans;
map<ll,ll> m;
bool endF = false;

void init(){
  rep(2001) visited[i] = false;
  endF = false;
  return;
}

void dfs(ll goal,ll now){
  if(now == n){
    ans.pb(goal);
    //cout << goal << endl;
    endF = true;
    return;
  }
  if(endF) return;
  //cout << goal << ' ' << now << endl;
  rep(n){
    if(visited[i]) continue;
    ll tmp = a[now] ^ b[i];
    if(tmp == goal){
      //cout << tmp << endl;
      visited[i] = true;
      dfs(goal,now+1);
      visited[i] = false;
    }
  }
  return;
}

int main(){
  cin >> n;
  rep(n){
    ll aa;
    cin >> aa;
    a.pb(aa);
  }
  rep(n){
    ll bb;
    cin >> bb;
    b.pb(bb);
  }
  map<ll,ll> canditate;
  rep(n) canditate[a[0] ^ b[i]]++;
  for(auto it = canditate.begin();it!=canditate.end();it++){
    init();
    dfs(it->fi,0);
  }
  cout << ans.size() << endl;
  sort(ALL(ans));
  rep(ans.size()) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
