#include <bits/stdc++.h>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define ALL(x) x.begin(),x.end()

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

const ll INF = numeric_limits<ll>::max()/4;

string x;
ll m;

bool solve(ll r){
  vector<ll> vec;
  ll M = m;
  while(M > 0){
    vec.push_back(M % r);
    M /= r;
  }
  reverse(ALL(vec));
  if(vec.size() > x.size()) return true;
  else if(vec.size() < x.size()) return false;
  else{
    rep(i,vec.size()){
      if(vec[i] < x[i] - '0') return false;
      else if(vec[i] > x[i] - '0') return true;
    }
    return true;
  }
}

int main(){
  cin >> x >> m;
  int mx = 0;
  rep(i,x.size()){
    mx = max(mx,x[i] - '0');
  }
  if(x.size() == 1){
    ll x0 = (int) x[0] - '0';
    if(x0 <= m) cout << "1" <<endl;
    else cout << "0" << endl;
    return 0;
  }
  ll left = 1;
  ll right = INF;
  while(left + 1 < right){
    ll md = (left+right)/2;
    if(solve(md)) left = md;
    else right = md;
  }
  cout << max(left - mx,(ll)0);
  return 0;
}
