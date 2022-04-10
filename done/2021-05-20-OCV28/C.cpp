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
ll n;
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

pll longest(int i1,int i2){
  ll mx = -1;
  ll ret1 = -1;ll ret2 = -1;
  ll i = i1;
  while(i <= i2){
    if(s[i] == '1'){
      ll cnt = 0;
      ll ind1 = i;
      while(s[i] != '0' && i<=i2){
        cnt++;
        i++;
      }
      if(mx < cnt){
        mx = cnt;
        ret1 = ind1;
        ret2 = i-1;
      }
    }
    else i++;
  }
  return mp(ret1,ret2);
}

ll cntS(int i1,int i2){
  ll ret = 0;
  for(int i=i1;i<=i2;i++){
    if(s[i] == '0') ret++;
  }
  return ret;
}

ll cntT(int i1,int i2){
  ll ret = 0;
  for(int i=i1;i<=i2;i++){
    if(t[i] == '0') ret++;
  }
  return ret;
}

void solve(int i1,int i2){
  pll P = longest(i1,i2);
  pll P1 = P;
  if(P.fi == -1) return;
  if(i1 >= i2) return;
  ll c1 = cntS(i1,P.fi);
  ll c3 = cntT(i1,P.fi);
  cout << i1 << ' ' << i2 << endl;
  cout << c1 << ' ' << c3 << endl;
  if(c1 != c3){
    if(c1 > c3){
      c1 = c1-c3;
      int now = P.fi;
      while(c1 && now >= 0){
        if(s[now] == '1') now--;
        else{
          swapS(now,P.se);
          P.se--;
          if(P.se == P.fi) break;
          c1--;
        }
      }
    }
    else{
      c1 = c3-c1;
      int now = P.se;
      while(c1 && now < n){
        if(s[now] == '1') now++;
        else{
          swapS(now,P.fi);
          P.fi++;
          if(P.se == P.fi) break;
          c1--;
        }
      }
    }
  }
  solve(i1,P.fi-1);
  solve(P.se+1,i2);
}

int main(){
  cin >> n >> s >> t;
  int now = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  rep(i,n){if(s[i] == '1') cnt1++;if(t[i] == '1') cnt2++;}
  if(cnt1 != cnt2){cout << "-1" << endl;return 0;}
  //  solve(0,s.size()-1);
  //  cout << s << endl << t << endl;
  //  cout << ans << endl;
  vll v1,v2;
  rep(i,n){if(s[i] == '0') v1.pb(i);}
  rep(i,n){if(t[i] == '0') v2.pb(i);}

  rep(i,v1.size()){
    if(v1[i] != v2[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
