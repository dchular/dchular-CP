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
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};

ll n;
ll a[1000005];
vll p;

void findPrime(){
  bool visited[1000005] = {};
  for(ll i = 2; i <= 1000000;i++){
    if(!visited[i]){
      visited[i] = true;
      p.pb(i);
      for(ll j = 2;i*j<=1000000;j++){
        visited[i*j] = true;
      }
    }
  }
}

bool check1(){
  findPrime();
  int m[1000005] = {0};
  rep(n){
    m[a[i]] ++;
    if(m[a[i]] > 1 && a[i] != 1) return false;
  }
  rep(p.size()){
    ll prime = p[i];
    ll cnt = 0;
    //cout << prime << ":" << endl;
    for(ll j = 1; j*prime <= 1000000;j++){
      if(m[prime*j] > 0) {
        cnt++;
        //cout << i*j << endl;
      }
    }
    if(cnt > 1) return false;
  }
  return true;
}

bool check2(){
  ll g = gcd(a[0],a[1]);
  rep(i,2,n){
    g = gcd(g,a[i]);
  }
  if(g == 1) return true;
  else return false;
}

int main(){
  cin >> n;
  rep(n) cin >> a[i];

  if(check1()) {
    cout << "pairwise coprime\n";
  }
  else if(check2()) cout << "setwise coprime\n";
  else cout << "not coprime\n";
  return 0;
}
