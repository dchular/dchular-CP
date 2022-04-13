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


struct Edge {
    long long to;
};
using Graph = vector<vector<Edge>>;
/* LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
    query(u,v): u と v の LCA を求める。計算量 O(logn)
    前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const Graph &G, int root = 0) { init(G, root); }
    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }
    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};
int get_dist(int u, int v) { return dist[u] + dist[v] - 2 * dist[query(u, v)]; }

int main(){
  ll n;
  cin >> n;
  Graph g(n);
  rep(n-1){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    Edge e;
    e.to = v;
    g[u].pb(e);
  }
  LCA(g,0);
  cout << get_dist(1,2);

  return 0;
}
