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

ll dis(pll p1, pll p2){
  ll dx = p1.fi - p2.fi;
  ll dy = p1.se - p2.se;
  return dx*dx + dy*dy;
}

bool isT(ll d1,ll d2,ll d3){
  if(d3-d1-d2 < 0) return true;
  __int128 t1 = 4*d1*d2;
  __int128 t2 = (d3-d1-d2) *(d3-d1-d2);
  
  return t1 > t2;
}

int main(){
  ll n;
  cin >> n;
  vpll v;
  rep(n){
    ll x,y;
    cin >> x >> y;
    v.pb({x,y});
  }
  ll cnt = 0,cnt2=0;
  rep(i1,n){
    rep(i2,i1+1,n){
      rep(i3,i2+1,n){
        pll p1 = v[i1];
        pll p2 = v[i2];
        pll p3 = v[i3];

        p2.fi -= p1.fi;
        p2.se -= p1.se;
        p3.fi -= p1.fi;
        p3.se -= p1.se;
        p1.fi -= p1.fi;
        p1.se -= p1.se;
        
        // ll d1 = dis(p1,p2);
        // ll d2 = dis(p1,p3);
        // ll d3 = dis(p2,p3);
        // double s1 = sqrt(d1);
        // double s2 = sqrt(d2);
        // double s3 = sqrt(d3);
        // if(s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) cnt2++;
        // if((p1.se * p2.fi == p1.fi*p2.se) && (p1.se * p3.fi == p1.fi*p3.se)){
        // if(isT(d1,d2,d3) && isT(d1,d3,d2) && isT(d3,d2,d1)){
          // cnt++;
        if(p3.se * p2.fi == p3.fi*p2.se){
          continue;
        }
        else{
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
  // cout << cnt2 << endl;
  return 0;
}
