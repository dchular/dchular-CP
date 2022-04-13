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

ll A[805][805];
ll n,k;
ll ans = INF;
vector <ll> ms;
bool flagR = true;
bool flagD = false;
bool flagRR = true;

void check(ll x,ll y){
  vll v;
  //cout << x << ' ' << y << endl;
  auto itr = ms.begin();
  // rep(i,ms.size()) {
  //   cout << *itr << ' ';
  //   itr++;
  // }
  // cout << endl;
  // system(pause);
  if(x != 0 || y != 0){
    // flagD = true Down
    // flagRR true Right false left
    // 移動してきた今x,yにいる
    if(flagD){
      flagD = false;
       rep(i,k){
        ll clearYouso = A[x+i][y-1];

        // cout << "kesu:";
        // cout << clearYouso << ' ';

        auto it = find(ms.begin(),ms.end(),clearYouso);
        ms.erase(it);
      }
      rep(i,k){
        // cout << "ireru0 ";
        // cout << A[x+i][y+k-1] << ' ';

        ms.pb(A[x+i][y+k-1]);
      }
    }
    else if(flagRR){
      rep(i,k){
        ll clearYouso = A[x-1][y+i];

      //  cout << "kesu:";
        // cout << clearYouso << ' ';

        auto it = find(ALL(ms),clearYouso);
        ms.erase(it);
      }
      rep(i,k){
        // cout << "ireru1 ";
        // cout << A[x+k-1][y+i] << ' ';

        ms.pb(A[x+k-1][y+i]);
      }
    }
    else{
      rep(i,k){
        ll clearYouso = A[x+k][y+i];

        // cout << "kesu:";
        // cout << clearYouso << ' ';

        auto it = find(ALL(ms),clearYouso);
        ms.erase(it);
      }
      rep(i,k){
        // cout << "ireru2 ";
        // cout << A[x][y+i] << ' ';

        ms.pb(A[x][y+i]);
      }
    }
  }
  ll index = k*k -1 - (k*k) /2;
  //cout << "max:" << v[index] << endl;
  auto it = ms.begin();
  sort(ALL(ms));
  // auto itre = ms.begin();
  //  rep(i,ms.size()) {
  //    cout << *itre << ' ';
  //    itre++;
  // }

  // cout << endl;
  // cout << "ireru:" << *it << endl;
  chmin(ans,ms[index]);
}

int main(){
  cin >> n >> k;

  rep(i,n){
    rep(j,n){
      cin >> A[i][j];
    }
  }

  // 左上のやつ
  ll x = 0;
  ll y = 0;

  rep(i,k){
    rep(j,k){
      ms.pb(A[i][j]);
    }
  }

  while(1){
    check(x,y);
    //cout << x << ' ' << y << endl;
    // 移動させる
    if(x+k >= n){
      if(flagR){
        y++;
        flagD = true;
        flagR = false;
      }
      else{
        x--;
        flagRR = false;
      }
    }
    else if(x <= 0){
      if(!flagR){
        y++;
        flagD = true;
        flagR = true;
      }
      else {
        flagRR = true;
        x++;
      }
    }
    else if(flagR){
      x++;
      flagRR = true;
    }
    else if(!flagR){
      x--;
      flagRR = false;
    }
    // 終わる条件
    if(y+k-1 >= n) break;
    if(n == k) break;
  }
  cout << ans << endl;
  return 0;
}
