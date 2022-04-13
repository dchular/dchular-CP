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
ll aa[205] = {0};
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

ll toPrint(string s){
  if(s.empty()) return 0;
  if(s[0] == '0' && s[1] == '0') return (ll)(s[2] - '0');
  if(s[0] == '0') return (ll)((s[1] - '0')*10 + s[2] - '0');
  return (ll)((s[0] - '0') * 100 +(s[1] - '0')*10 + s[2] - '0');
}

void check(ll ul){
  rep(i,v[ul].size()){
    rep(j,i+1,v[ul].size()){
      string s1 = v[ul][i];
      string s2 = v[ul][j];
      vll v1,v2;
      for(int k=0; k+2<s1.size();k+=3){
        string ss =  "";
        ss += s1[k];
        ss += s1[k+1];
        ss += s1[k+2];
        ll a = toPrint(ss);
        v1.pb(a);
      }
      for(int k=0; k+2<s2.size();k+=3){
        string ss =  "";
        ss += s2[k];
        ss += s2[k+1];
        ss += s2[k+2];
        ll a = toPrint(ss);
        v2.pb(a);
      }
      sort(ALL(v1));
      sort(ALL(v2));

      bool flag = true;
      if(v1.size() > v2.size()){
        rep(k,v2.size()){
          if(v1[k] == v2[k]) flag = false;
        }
      }
      else{
        rep(k,v1.size()){
          if(v1[k] == v2[k]) flag = false;
        }
      }
      if(flag){
        cout << "Yes" << endl;
        if(v1.size() > v2.size()){
          cout << v2.size() << ' ';
          rep(k,v2.size()) cout << v2[k] << ' ';
          cout << endl;
          cout << v1.size() << ' ';
          rep(k,v1.size()) cout << v1[k] << ' ';
          cout << endl;
          endF = true;
          return;
        }
        else {
          cout << v1.size() << ' ';
          rep(k,v1.size()) cout << v1[k] << ' ';
          cout << endl;
          cout << v2.size() << ' ';
          rep(k,v2.size()) cout << v2[k] << ' ';
          cout << endl;
          endF = true;
          return;
        }
      }
    }
  }
}

void solve(int now,int doko,int ul,string s){
  if(endF) return;
  if(now <= 0){
    ul = ul%200;
    v[ul].pb(s);
    if(v[ul].size() >= 2){
      check(ul);
      if(endF) return;
    }
    return;
  }
  rep(i,doko,n){
    string ss = s;
    ss += toString(i+1);
    solve(now-1,i+1,ul+a[i],ss);
  }
  return;
}


int main(){

  cin >> n;

  rep(i,n){
    ll t;
    cin >> t;
    aa[t%200] ++;
    a[i] = t%200;
    v[t%200].pb(toString(i+1));
    if(aa[t%200] == 2){
      cout << "Yes" << endl;
      cout << 1 << ' ' << toPrint(v[t%200][0]) <<' '<< endl;
      cout << 1 << ' ' << toPrint(v[t%200][1]) <<' '<< endl;
      return 0;
    }
  }
  rep(i,2,11){
    solve(i,0,0,"");
    if(endF) return 0;
  }
  cout << "No" << endl;
  return 0;
}
