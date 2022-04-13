#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
//#include <bits/stdc++.h>
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
const ll MAX = 400000;
const int MOD = 3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int toInt(char a){
  if(a == 'B') return 0;
  if(a == 'W') return 1;
  if(a == 'R') return 2;
  return 0;
}

char change(char a,char b){
  int A = toInt(a);
  int B = toInt(b);
  int C = (3 - (A+B)%3 )%3;
  //cout << A << B << C <<endl;
  if(C == 0) return 'B';
  if(C == 1) return 'W';
  if(C == 2) return 'R';
  return 'B';
}
char change2(int C){
  if(C == 0) return 'B';
  if(C == 1) return 'W';
  if(C == 2) return 'R';
  return 'B';
}
int find(int a){
  int cnt = 1;
  while(a>cnt){
    cnt*=2;
  }
  return cnt;
}

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ll n;
  cin >> n;
  // 前処理
  COMinit();
  string s;
  cin >> s;
  ll sum = 0;
  rep(i,s.size()){
    sum += COM(n-1,i) % 3;
  }
  if((n-1)%2 == 1) sum = (3-sum%3) % 3;

  cout << change2(sum) << endl;
  return 0;
}
