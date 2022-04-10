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
#define in(x,y)(0<=(x)&&(x)<h&&0<=(y)&&(y)<w)

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

string s,t;
ll ans = 0;
void swapS(int i1,int i2){
  char c = s[i1];
  s[i1] = s[i2];
  s[i2] = c;
  ans++;
  return;
}

void swapS2(int i1,int i2, ll plus){
  char c = s[i1];
  s[i1] = s[i2];
  s[i2] = c;
  ans+= plus;
}

int main(){
  ll n;
  cin >> n >> s >> t;
  int now = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  rep(i,n){if(s[i] == '1') cnt1++;if(t[i] == '1') cnt2++;}
  if(cnt1 != cnt2){cout << "-1" << endl;return 0;}
  while(s!=t && now < n){
    if(s[now] == t[now]){
      now++;
    }
    else{
      if(t[now] == '0'){
        int now2 = now;
        while(s[now2] != '0'){
          now2++;
        }
        swapS(now,now2);
      }
      else{//t[now] == '1' s[now] == '0'
        int now2 = now;
        while(s[now2] != '1'){
          now2++;
        }
        if(now2 != now+1){
          swapS2(now,now2,now2-now);
        }
        else{
          while(s[now2] != '0' && t[now2] != '0' && now2 < n){
            now2++;
          }
          if(s[now2] == '0') now2--;
          swapS(now,now2);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
