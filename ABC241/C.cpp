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

set <string> makable;

void make(ll i,ll j){
  string s = "######";
  s[i] = '.';
  s[j] = '.';
  makable.insert(s);
  return;
}

int main(){
  ll n;
  cin >> n;
  string s[1005];
  rep(n){
    cin >> s[i];
  }
  rep(6){
    rep(j,6){
      make(i,j);
    }
  }
  makable.insert("######");
  rep(n){
    rep(j,n){
      string check1 = "";
      string check2 = "";
      string check3 = "";
      string check4 = "";
      rep(k,6){
        if(j+k < n) check1 += s[i][j+k];
        if(j+k < n) check2 += s[j+k][i];
        if(i+k < n) check3 += s[i+k][j+k];
        if(j-k >= 0 && i+k < n) check4 += s[i+k][j-k];
      }
      // cout << check1 << endl << check2 << endl;
      if(makable.find(check1) != makable.end() || makable.find(check2) != makable.end()
       || makable.find(check3) != makable.end() || makable.find(check4) != makable.end()){
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
