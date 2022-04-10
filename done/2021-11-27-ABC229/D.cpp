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

int main(){
  string s;
  ll k;
  cin >> s >> k;
  ll ruiseki[200005] = {0};
  rep(s.size()){
    if(i != 0) ruiseki[i] = ruiseki[i-1];
    if(s[i] == '.') ruiseki[i]++;
  }
  ll ans = 0;
  ll r = 0;
  rep(l,s.size()){
    while(1){
      if(l>0 && ruiseki[r] - ruiseki[l-1] > k) break;
      if(l==0 && ruiseki[r] > k) break; 
      if(r==s.size()) break;
      r++;
      // cout << l << ' ' << r << endl;
    }
    chmax(ans,r-l);
  }
  cout << ans << endl;
  return 0;
}


/*
ll ccnt = 0;
  rep(s.size()){
    if(s[i] == '.') ccnt++;
  }
  if(ccnt <= k){
    cout << s.size() << endl;
    return 0;
  }

  ll sub = 0;
  ll j1 = 0,j2 = s.size()-1;
  while(s[j1] == '.'){
    j1++;
  }
  while(s[j2] == '.'){
    j2--;
  }
  string ss = "";
  rep(i,j1,j2+1){
    ss += s[i];
  }
  sub = s.size() - ss.size();
  s = ss;
  j2 = sub - j1;

  // cout << j1 <<  endl << j2;
  // cout << s << endl;
  ll j = 0;
  vll vx,vc;
  if(j1 != 0) {
    vx.pb(0);
    vc.pb(j1);
  }
  
  while(j < s.size()){
    if(s[j] == 'X'){
      ll cnt = 0;
      while(s[j] == 'X' && j < s.size()){
        j++;
        cnt++;
      }
      vx.pb(cnt);
    }
    if(s[j] == '.'){
      ll cnt = 0;
      while(s[j] == '.' && j < s.size()){
        j++;
        cnt++;
      }
      vc.pb(cnt);
    }
  }
  if(j2 != 0){
    vx.pb(0);
    vc.pb(j2);
  }

  ll cnow = 0;
  ll xnow = 0;
  ll index = -1;
  ll ans = 0;
  vx.pb(0);
  vc.pb(k);
  rep(i,vc.size()){
    // cout << cnow << ' ' << xnow << ' ' << index << ' ' << i << endl;
    if(cnow + vc[i] <= k){
      cnow += vc[i];
      xnow += vx[i+1];
      if(index == -1) {
        index = i;
        xnow = vx[i] + vx[i+1];
      }
    }
    else{
      chmax(ans,xnow + k);
      if(index == -1) continue;
      while(cnow + vc[i] > k && index != i){
        cnow -= vc[index];
        xnow -= vx[index];
        index++;
      }
      if(cnow + vc[i] <= k){
        cnow += vc[i];
        xnow += vx[i+1];
      }
      else index = -1;
    }
  }
  cout << ans << endl;
  */