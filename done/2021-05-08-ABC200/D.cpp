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

vector<string> v[205];
ll a[205] = {0};
bool endF = false;
ll n;

string toString(ll a){
  string s = "";
  if(a<10) s+= "0";
  if(a<100) s+= "0";
  s += to_string(a);
  return s;
}

void vPrint(vll ve){
  cout << ve.size() << ' ';
  for(ll val :ve){
    cout << val << ' ';
  }
  cout << endl;
  return;
}

void printAns(ll amari){
  string s1 = v[amari][0];
  string s2 = v[amari][1];
  vll v1,v2;
  for(int k=0; k+2<s1.size();k+=3){
    v1.pb(stoll(s1.substr(k,3)));
  }
  for(int k=0; k+2<s2.size();k+=3){
    v2.pb(stoll(s2.substr(k,3)));
  }
  cout << "Yes" << endl;
  if(v1.size() > v2.size()){
    vPrint(v2);
    vPrint(v1);
  }
  else {
    vPrint(v1);
    vPrint(v2);
  }
  endF = true;
}

void solve(int now,int doko,ll amari,string s){
  if(endF) return;
  if(now <= 0){
    amari %= 200;
    v[amari].pb(s);
    if(v[amari].size() >= 2){
      printAns(amari);
    }
    return;
  }
  rep(i,doko,n){
    string ss = s;
    ss += toString(i+1);
    solve(now-1,i+1,amari+a[i],ss);
  }
  return;
}

int main(){
  cin >> n;
  rep(i,n){
    ll t;cin >> a[i];
    a[i]%=200;
  }
  rep(i,1,11){
    solve(i,0,0,"");
    if(endF) return 0;
  }
  cout << "No" << endl;
  return 0;
}
