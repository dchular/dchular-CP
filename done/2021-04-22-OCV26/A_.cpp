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
  int n,q;
  cin >> n >> q;
  multiset<int> ms[MAX];
  map<int,int> mp;
  int mpK[MAX];
  int mpR[MAX];
  rep(i,n){
    int a,b;
    cin >> a >> b;
    ms[b].insert(a);
    //mp[a] = b;
    mpK[i+1] = b;
    mpR[i+1] = a;
  }
  multiset<int> saikyo;
  rep(i,MAX){
    if(ms[i].size() == 0) continue;
    else {
      auto itr = ms[i].rbegin();
      //cout << i << ' ' << *itr << endl;
      saikyo.insert(*itr);
    }
  }
  rep(i,q){
    int c,d;
    cin >> c >> d;
    int know = mpK[c];
    int rating = mpR[c];
    // saikyo から元と新を消す
    saikyo.erase(saikyo.find(*ms[know].rbegin()));
    if(ms[d].size() != 0) saikyo.erase(saikyo.find(*ms[d].rbegin()));
    // 幼稚園転入手続き
    ms[know].erase(ms[know].find(rating));
    ms[d].insert(rating);
    mpK[c] = d;
    // saikyo更新
    if(ms[know].size() != 0) saikyo.insert(*ms[know].rbegin());
    saikyo.insert(*ms[d].rbegin());
    // saikyo出す
    cout << *saikyo.begin() << endl;
  }
  return 0;
}
