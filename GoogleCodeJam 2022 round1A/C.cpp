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

vll E[15];
ll e,w;
string makeStr(ll i){
  string ret = "";
  rep(j,w){
    rep(k,E[i][j]){
      char c = j+1 + '0';
      ret += c;
    }
  }
  return ret;
}

ll calcCost(string s1,string s2){
  ll same = 0;
  rep(s2.size()){
    if(i < s1.size() && s2[i] == s1[i]){
      same++;
    }
    else break;
  }
  return s1.size() - same + s2.size() - same;
}

void solve(){
  cin >> e >> w;
  rep(15) E[i].clear();

  rep(e){
    rep(j,w){
      ll in;
      cin >> in;
      E[i].pb(in);
    }
  }

  map <string, ll> m[15];
  
  string fi = makeStr(0);
  do{
    m[0][fi] = fi.size();
  } while(next_permutation(ALL(fi)));

  rep(e-1){
    string now = makeStr(i);
    string next = makeStr(i+1);
    
    vector<string> nowS,nextS;
    for(auto it = m[i].begin(); it != m[i].end();it++){
      string s = it->first;
      nowS.pb(s);
    }
    do{
      nextS.pb(next);
    } while(next_permutation(ALL(next)));
    
    rep(j,nowS.size()){
      rep(k,nextS.size()){
        string snow = nowS[j];
        string snext = nextS[k];
        
        ll cost = calcCost(snow,snext);
        ll val = cost + m[i][snow];
        if(m[i+1].find(snext) == m[i+1].end()) m[i+1][snext] = val;
        else if(m[i+1][snext] > val) m[i+1][snext] = val;
      }
    }
  }

  ll ans = INF;
  ll length = 0;
  for(auto it = m[e-1].begin(); it != m[e-1].end();it++){
    chmin(ans,it->second);
    string s = it->first;
    length = s.size();
  }
  ans += length;
  cout << ans << endl;
}

int main(){
  ll T;
  cin >> T;
  rep(T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
