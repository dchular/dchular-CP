#include <bits/stdc++.h>
//#include <atcoder/lazysegtree>
//#include <atcoder/segtree>
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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const ll INF = numeric_limits<ll>::max()/4;
const ll MAX = 200005;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<char> v;
int m[300] = {0};

void solve(string s){
  rep(i,s.size()){
    if(m[s[i]] == 0){
      v.pb(s[i]);
      m[s[i]]++;
    }
  }
}

ll solve2(string s){
  ll ret = 0;
  rep(i,s.size()){
    ret += m[s[i]];
    ret *= 10;
  }
  return ret/10;
}

int main(){
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  solve(s1);
  solve(s2);
  solve(s3);
  if(v.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  while(v.size() != 10) v.pb('Z');
  sort(ALL(v));
  do{
    ll n1=0,n2=0,n3=0;
    rep(i,v.size()){
      m[v[i]] = i;
    }
    n1 = solve2(s1);
    n2 = solve2(s2);
    n3 = solve2(s3);
    if(m[s1[0]] == 0 ||m[s2[0]] == 0 ||m[s3[0]] == 0) continue;
    if(n1 + n2 == n3){
      cout << n1 << endl << n2 << endl << n3 << endl;
      return 0;
    }
  }while(next_permutation(ALL(v)));
  cout << "UNSOLVABLE" << endl;
  return 0;
}
