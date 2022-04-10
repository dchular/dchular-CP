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
#include <vector>
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

//int gcd(int a,int b){return b?gcd(b,a%b):a;}
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

int main(){
  string s;
  cin >> s;
  int sz = s.size();
  s+= '#';
  int now = 0;
  ll ans[100005] = {0};
  rep(i,sz) ans[i] = -1;
  rep(i,sz){
    if(s[i] == 'R' && s[i+1] == 'L'){
      int r = 1;
      int l = 1;
      int rCnt = i-1;
      while(rCnt >= 0){
        if(s[rCnt] == 'R')
          rCnt --;
        else break;
      }
      rCnt = i - 1 - rCnt;
      int leftCnt = i+2;
      while(s[leftCnt] == 'L'){
        leftCnt++;
      }

      leftCnt -= (i+2);
    //  cout << rCnt << ' ' << leftCnt << ' ';
      r += (rCnt)/2;
      l += (rCnt)/2;
      if(rCnt != 0){
        if(rCnt %2 == 1) l++;
      }

      r += (leftCnt)/2;
      l += (leftCnt)/2;
      if(leftCnt != 0){
        if(leftCnt %2 == 1) r++;
      }
      // << r << ' ' << l << endl;
      ans[i] = r;
      ans[i+1] = l;
    }
  }
  rep(i,sz){
    if(ans[i] == -1) ans[i] = 0;
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
