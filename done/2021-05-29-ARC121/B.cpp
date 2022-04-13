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

ll solve(vll v1,vll v2){
  ll ret = INF;
  int i1 = 0,i2 = 0;
  if(v1.size() == 0 || v2.size() == 0) return ret;
  while(1){
    chmin(ret,abs(v1[i1] - v2[i2]));
    if(i1 >= v1.size()-1 && i2 >= v2.size()-1) break;
    if(i1 >= v1.size()-1) i2++;
    else if(i2 >= v2.size()-1) i1++;
    else if(v1[i1] > v2[i2]) i2++;
    else i1++;
  }
  return ret;
}

int main(){
  ll n;
  cin >> n;
  vll vr,vg,vb;

  rep(i,2*n){
    ll a;
    char c;
    cin >> a >> c;
    if(c == 'R') vr.pb(a);
    if(c == 'G') vg.pb(a);
    if(c == 'B') vb.pb(a);
  }
  sort(ALL(vr));
  sort(ALL(vg));
  sort(ALL(vb));
//r 4 g 6 b 10
  ll rg = solve(vr,vg);ll gr = rg;
  ll rb = solve(vr,vb);ll br = rb;
  ll bg = solve(vb,vg);ll gb = bg;
  ll cntR = vr.size();
  ll cntG = vg.size();
  ll cntB = vb.size();
  int fR = cntR%2,fG = cntG%2,fB = cntB%2;
  //cout << fR << ' ' << fG << ' ' << fB << endl;
  ll ans = INF;
  if(!fR && !fG && !fB){
    cout << "0" << endl;
    return 0;
  }
  else if(fR == 1 && fG == 1){
    chmin(ans,rg);
    chmin(ans,rb + bg);
  }
  else if(fR == 1 && fB == 1){
    chmin(ans,rb);
    chmin(ans,rg + bg);
  }
  else if(fG == 1 && fB == 1){
    chmin(ans,gb);
    chmin(ans,rg + rb);
  }
  cout << ans << endl;
  //cout << rg << ' ' << rb << ' ' << bg << endl;
  return 0;
}
