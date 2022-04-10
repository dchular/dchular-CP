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

ll ans;
void check(pll p1,pll p2,pll p3,pll p4){
  
}

void solve(){
  ll n;
  cin >> n;
  vpll a,b;
  rep(n){ll aa; cin >> aa;a.pb({aa,i})}
  rep(n){ll bb; cin >> bb;b.pb({bb,i+n})}
  vpll v1,v2,v3,v4;
  v1.pb({abs(a[0].fi-a[n-1].fi),a[n-1].se});
  v3.pb({abs(b[0].fi-a[n-1].fi),a[n-1].se});
  v4.pb({abs(b[n-1].fi-a[n-1].fi),a[n-1].se});
  
  v2.pb({abs(a[n-1].fi-a[0].fi),a[0].se});
  v3.pb({abs(b[0].fi-a[0].fi),a[0].se});
  v4.pb({abs(b[n-1]-a[0].fi),a[0].se});
  
  v1.pb({abs(a[0]-b[n-1].fi),b[n-1].se});
  v2.pb({abs(a[n-1]-b[n-1].fi),b[n-1].se});
  v3.pb({abs(b[0]-b[n-1].fi),b[n-1].se});
  
  v1.pb({abs(a[0]-b[0].fi),b[0].se});
  v2.pb({abs(a[n-1]-b[0].fi),b[0].se});
  v4.pb({abs(b[n-1]-b[0].fi),b[0].se});
  
  vll a1,a2;
  vll b1,b2;
  rep(i,1,n) a1.pb(a[i]);
  rep(i,0,n-1) a2.pb(a[i]);
  rep(i,1,n) b1.pb(a[i]);
  rep(i,0,n-1) b2.pb(a[i]);
  
  ll mn1,mn2,mn3,in1,in2,in3;
  // a0
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(a1[i] - a[0]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v1.pb(mn1,in1);
  if(in2 != INF) v1.pb(mn2,in2);
  if(in3 != INF) v1.pb(mn3,in3);
  // an-1
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(a2[i] - a[n-1]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v2.pb(mn1,in1);
  if(in2 != INF) v2.pb(mn2,in2);
  if(in3 != INF) v2.pb(mn3,in3);
  //b0
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(b1[i] - b[0]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v3.pb(mn1,in1);
  if(in2 != INF) v3.pb(mn2,in2);
  if(in3 != INF) v3.pb(mn3,in3);
  //bn-1
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(b2[i] - b[n-1]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v4.pb(mn1,in1);
  if(in2 != INF) v4.pb(mn2,in2);
  if(in3 != INF) v4.pb(mn3,in3);
  // a0
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(b[i] - a[0]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v1.pb(mn1,in1);
  if(in2 != INF) v1.pb(mn2,in2);
  if(in3 != INF) v1.pb(mn3,in3);
  // an-1
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(b[i] - a[n-1]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v2.pb(mn1,in1);
  if(in2 != INF) v2.pb(mn2,in2);
  if(in3 != INF) v2.pb(mn3,in3);
  //b0
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(a[i] - b[0]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v3.pb(mn1,in1);
  if(in2 != INF) v3.pb(mn2,in2);
  if(in3 != INF) v3.pb(mn3,in3);
  //bn-1
  mn1=INF;mn2=INF;mn3=INF;
  in1=INF;in2=INF;in3=INF;
  rep(n){
    ll val = abs(a[i] - b[n-1]);
    if(mn1 > val){
      mn3 = mn2;in3=in2;
      mn2 = mn1;in2=in1;
      mn1 = val;in1=i;
    }
  }
  if(in1 != INF) v4.pb(mn1,in1);
  if(in2 != INF) v4.pb(mn2,in2);
  if(in3 != INF) v4.pb(mn3,in3);

  ans = INF;
  rep(i1,v1.size()){
    rep(i2,v2.size()){
      rep(i3,v3.size()){
        rep(i4,v4.size()){
          check(v1[i1],v2[i2],v3[i3],v4[i4]);
        }
      }
    }
  }
}

int main(){
  ll testCase;
  cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
