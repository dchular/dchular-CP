#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
#include <list>
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
const ll MAX = 200000;
const int MOD = 1e9 + 7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll n,k,r,s,p;
string t;

int calc(char c){
  if (c == 'r') return p;
  if (c == 'p') return s;
  if (c == 's') return r;
  return 0;
}

int main(){
  cin >> n >> k >> r >> s >> p >> t;
  rep(i,k){
    t += '#';
  }
  int memo[100005] = {0};
  ll ans = 0;
  rep(i,n){
    if(t[i] != t[i+k]){
      if(memo[i] == -1) ans+=0;
      else ans += calc(t[i]);
    }
    else{
      if(memo[i] == -1) ans+=0;
      else {
        memo[i+k] = -1;
        ans += calc(t[i]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
