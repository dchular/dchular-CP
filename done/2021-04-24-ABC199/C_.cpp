#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
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
const ll MAX = 5 * 1e2;
const int MOD = 998244353;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  int n,q;
  string s;
  cin >> n >> s >> q;
  char s1[200005],s2[200005];
  int sz = s.size()/2;
  rep(i,sz){
    s1[i] = s[i];
  }
  rep(i,sz){
    s2[i] = s[i+sz];
  }
  int cnt = 0;
  rep(i,q){
    int t,a,b;
    cin >> t >> a >> b;
    a--;
    b--;
    if(t == 1){
      if(a >= sz && b >= sz){
        a-= sz;
        b-= sz;
        if(cnt%2 == 1){
          char temp = s1[a];
          s1[a]=s1[b];
          s1[b] = temp;
          continue;
        }
        char temp = s2[a];
        s2[a]=s2[b];
        s2[b] = temp;
      }
      else if(a >= sz && b < sz){
        a-= sz;
        if(cnt%2 == 1){
          char temp = s1[a];
          s1[a] = s2[b];
          s2[b] = temp;
          continue;
        }
        char temp = s2[a];
        s2[a] = s1[b];
        s1[b] = temp;
      }
      else if(a < sz && b < sz){
        if(cnt%2 == 1){
          char temp = s2[a];
          s2[a] = s2[b];
          s2[b] = temp;
          continue;
        }
        char temp = s1[a];
        s1[a] = s1[b];
        s1[b] = temp;
      }
      else if(a < sz && b >= sz){
        b-= sz;
        if(cnt%2 == 1){
          char temp = s2[a];
          s2[a] = s1[b];
          s1[b] = temp;
          continue;
        }
        char temp = s1[a];
        s1[a] = s2[b];
        s2[b] = temp;
      }
    }
    if(t == 2){
      cnt++;
    }
  }
  if(cnt%2 == 1){
    rep(i,sz){
      cout << s2[i];
    }
    rep(i,sz){
      cout << s1[i];
    }
    cout << endl;
    return 0;
  }
  rep(i,sz){
    cout << s1[i];
  }
  rep(i,sz){
    cout << s2[i];
  }
  cout << endl;
  return 0;
}
