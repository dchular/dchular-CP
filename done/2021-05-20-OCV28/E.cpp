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

ll N;
ll A[1 << 18], B[1 << 18],W[1 << 18];
ll dp[1 << 18];
vector<pll > G[200005];

void dfs(ll pos, ll pre) {
  if(pre != -1){
    dp[pos] = G[pre][pos].se;
    cout << dp[pos] << endl;
  }
  else dp[pos] = 0;
	for (pll ii : G[pos]) {
    ll i = ii.fi;
    if (i == pre) continue;
		dfs(i, pos);
		dp[pos] ^= dp[i];
	}
}

int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i] >> W[i];
		G[A[i]].push_back(mp(B[i],W[i]));
		G[B[i]].push_back(mp(A[i],W[i]));
	}

	// Step #2. 深さ優先探索（DFS）
	dfs(1, -1);
  rep(i,N) cout << dp[i] << ' ';
  cout << endl;
	// Step #3. 答えを求める
	long long Answer = 0;
	for (int i = 1; i <= N - 1; i++) {
		long long r = min(dp[A[i]], dp[B[i]]);
		Answer += r * (N - r);
	}
	cout << Answer << endl;

  return 0;
}
