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
#define mt make_tuple
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

struct compare {
    bool operator() (const tuple<ll,ll,ll>& t1, const tuple<ll,ll,ll>& t2) const {
      if(get<0>(t1) != get<0>(t2)) return get<0>(t1) > get<0>(t2);
      if(get<2>(t1) != get<2>(t2)) return get<2>(t1) > get<2>(t2);
      else return get<1>(t1) > get<1>(t2);
    }
};


int main(){
  ll n,m;
  cin >> n >> m;
  vll a(n),b(n);
  vll c(m),d(m);
  rep(n) cin >> a[i];
  rep(n) cin >> b[i];
  rep(m) cin >> c[i];
  rep(m) cin >> d[i];
  multiset <tuple<ll,ll,ll>,compare> chocoBox,box;
  
  rep(n) chocoBox.insert(mt(a[i],b[i],1));
  rep(m) chocoBox.insert(mt(c[i],d[i],0));
   
  for(auto it = chocoBox.begin(); it!= chocoBox.end(); it++){
    tuple<ll,ll,ll> T = *it;
    if(get<2>(T) == 0){
      box.insert(T);
      continue;
    }
    else{
      tuple<ll,ll,ll> TT = mt(get<0>(T),get<1>(T),0);
      auto index = box.lower_bound(TT);
      if(index == box.end()){
        cout << "No\n";
        return 0;
      }
      else box.erase(index);
    }
  }
  cout << "Yes\n";
  return 0;
}
