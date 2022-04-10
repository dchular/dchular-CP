#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>
//#include <bits/stdc++.h>
// @coder ABC196
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

int main(){
  ll n;
  cin >> n;
  ll border1 = -INF, border2 = INF,add=0;
  rep(i,0,n){
    ll a,t;
    cin >> a >> t;
    if(t == 1){
      add += a;
      border1 += a;
      border2 += a;
    }
    if(t == 2){
      border1 = max(border1,a);
      border2 = max(border2,a);
    }
    if(t == 3){
      border1 = min(border1,a);
      border2 = min(border2,a);
    }
    //cout << border1 << ' ' << border2 << endl << endl;
  }
  ll q;
  //cout << border1 << ' ' << border2 << endl << endl;
  cin >> q;
  rep(i,0,q){
    ll x;
    cin >> x;
    x+= add;
    if(x < border1) cout << border1;
    else if(x > border2) cout << border2;
    else cout << x;
    cout << endl;
  }
  //cout <<
  return 0;
}
