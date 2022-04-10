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

void solve(){
  ll n;
  cin >> n;
  vll h(n);
  rep(n) cin >> h[i];
  ll mx = 0;
  rep(n){
    chmax(mx,h[i]);
  }
  // queue <ll> s;
  // queue <ll> odd;
  // rep(n){
  //   if(mx == h[i]) continue;
  //   if((mx - h[i]) %2 == 0) s.push(h[i]);
  //   else odd.push(h[i]);
  // }
  // ll ans = 1;
  // while(!s.empty() || !odd.empty()){
  //   if(ans %2 == 1){
  //     if(!odd.empty()){
  //       ll val = odd.front();
  //       odd.pop();
  //       if(val+1 != mx){
  //         // cout << val+1 << endl;
  //         s.push(val+1);
  //         // if(mx - (val+1) %2 != 0) cout << "YABAI";
  //         // if(mx <= (val+1)) cout << "YABAI";
  //       }
  //       if(val+1 == mx) {
  //         // cout << "IINE";
  //       }
  //     }
  //     else{
  //       ll val = s.front();
  //       if(val+2 != mx && s.size() + odd.size() == 1){
  //         continue;
  //         ans++;
  //       }
  //       s.pop();
  //       if(val+1 != mx){
  //         odd.push(val+1);
  //         // if(mx - (val+1) %2 != 1) cout << "YABAI";
  //         // if(mx <= (val+1)) cout << "YABAI";
  //       }
  //     }
  //   }
  //   else{
  //     if(!s.empty()){
  //       ll val = s.front();
  //       s.pop();
  //       // cout << val << endl;
  //       if(val+2 != mx){
  //         s.push(val+2);
  //         // if(mx - (val+2) %2 != 0) cout << "YABAI";
  //         // if(mx <= (val+2)) cout << "YABAI";
  //       }
  //       if(val+2 == mx) {
  //         // cout << "IINE";
  //       }
  //     }
  //     else{
  //       ll val = odd.front();
  //       // cout << val << endl;
  //       if(val+2 > mx) {
  //         ans++;
  //         continue;
  //       }
  //       odd.pop();
  //       if(val+2 != mx){
  //         odd.push(val+2);
  //         // if(mx - (val+2) %2 != 1) cout << "YABAI";
  //         // if(mx <= (val+2)) cout << "YABAI";
  //       }
  //       if(val+2 == mx) {
  //         // cout << "IINE";
  //       }
  //     }
  //   }
  //   ans++;
  // }
  // cout << ans-1 << endl;
  ll diff = 0;
  rep(n){
    diff += mx-h[i];
  }
  ll flag = 0;
  ll cnt = 0;
  rep(n){
    if(mx - h[i] %2 == 1) cnt++;
  }
  ll tmp = (diff / 3)*2 + diff % 3;
  ll cntKisu = tmp/2 + tmp%2;
  if(cnt > cntKisu) flag = 1;
  if(tmp %2 == 1) flag ++;
  cout << (diff / 3)*2 + diff % 3 + flag << endl;
}

int main(){
  ll testCase;
  cin >> testCase;
  rep(testCase){
    solve();
  }
  return 0;
}
