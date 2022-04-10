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

const ll h_max = 52*52*52;//52*52*52
vll G[h_max];
vll rG[h_max];
vector<string> words;
ll WL[h_max];//-1->L 1->Win 0 -> Draw  -2 -> unknown
bool visited[h_max];
ll cnt[h_max];

// int char_to_int(char c){
//     if('A'<=c && c<='Z') return c-'A';
//     else return c-'a'+26;
// }
// int Hash(string s){
//     return char_to_int(s[0]) * 52 * 52 + char_to_int(s[1]) * 52 + char_to_int(s[2]);
// }
// 普通に小文字だけだとおもてた
ll Hash(string s){
  ll ret = 0;
  ll a;
  if(s[0] >= 'A' && s[0] <='Z') a = s[0] - 'A' + 26;
  else a = s[0] - 'a';
  ret += a * 52*52;

  if(s[1] >= 'A' && s[1] <='Z') a = s[1] - 'A' + 26;
  else a = s[1] - 'a';
  ret += a *52;

  if(s[2] >= 'A' && s[2] <='Z') a = s[2] - 'A' + 26;
  else a = s[2] - 'a';
  ret += a ;

  return ret;
}

void init(){
  rep(h_max) visited[i] = false;
  rep(h_max) WL[i] = -2;
  rep(h_max) cnt[i] = 0;
}

// void dfs(ll now){
//   if(visited[now]) return;
//   visited[now] = true;
//   if(G[now].size() == 0){
//     WL[now] = -1;// Lose
//     return;
//   }
//   // if all W its L
//   // at least 1 L Win
//   // else Draw
//   ll winFlag = 1;
//
//   for(ll to:G[now]){
//     if(WL[to] == -2){//unknown
//       dfs(to);
//     }
//     if(WL[to] == -1){//lose
//       WL[now] = 1;// Win
//     }
//     winFlag *= WL[to];
//   }
//   if(WL[now] == -2){
//     if(winFlag == 1) WL[now] = -1;
//     else WL[now] = 0;
//   }
//   return;
// }

int main(){
  ll n;
  cin >> n;
  //cout << Hash("ABC");
  rep(n){
    string s;
    cin >> s;
    string start,end;
    start = s.substr(0,3);
    end = s.substr(s.size()-3,3);
    G[Hash(start)].pb(Hash(end));
    rG[Hash(end)].pb(Hash(start));
  //  cout << "wordtest:" << start << ' ' << end << endl;
  //  cout << "hashtest:"<<Hash(start) << endl;

    words.pb(end);
  }
  init();
  // rep(h_max){
  //   dfs(i);
  // }
  queue<ll> q;
  rep(h_max){
    if(G[i].size() == 0) {
      WL[i] = -1;
      q.push(i);
    }
  }
  while(!q.empty()){
    ll now = q.front();q.pop();
    for(ll to:rG[now]){
      if(WL[to] != -2) continue;
      if(WL[now] == -1) {
        WL[to] = 1;
        q.push(to);
      }
      if(WL[now] == 1){
        cnt[to]++;
        if(cnt[to] == G[to].size()){
          WL[to] = -1;
          q.push(to);
        }
      }
    }
  }
  rep(words.size()){
    ll winL = WL[Hash(words[i])];
    if(winL == 1){
      cout << "Aoki\n";
    }
    else if(winL == -1){
      cout << "Takahashi\n";
    }
    else cout << "Draw\n";
  }
  return 0;
}
