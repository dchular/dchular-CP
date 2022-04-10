#include <bits/stdc++.h>
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
const ll MAX = 200005;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  ll n;
  cin >> n;
  cout << "6 10 15 ";
  n-=3;
  ll roku = 2;
  ll jyu  = 2;
  ll jyugo = 2;
  ll mx = 10000;
  vll v;
  v.pb(6);v.pb(10);v.pb(15);
  int memo[10005] = {0};
  while(n > 0){
    if(roku * 6 <= 10000 && memo[roku*6] == 0){
      cout << roku * 6 << ' ';
      memo[roku*6]++;
      n--;
      roku++;
    }
    else if(jyu * 10 <= 10000 && memo[jyu*10] == 0){
      cout << jyu * 10 << ' ';
      memo[jyu*10]++;
      n--;
      jyu++;
    }
    else if(jyugo * 15 <= 10000 && memo[jyugo*15] == 0){
      cout << jyugo * 15 << ' ';
      memo[jyugo*15]++;
      n--;
      jyugo++;
    }
    else {
      if(roku * 6 <= 10000) roku++;
      else if(jyu * 10 <= 10000) jyu++;
      else if(jyugo * 15 <= 10000) jyugo++;
    }
  }
  cout << endl;
  return 0;
}
