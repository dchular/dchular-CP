#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;



int main(){
  ll k;
  string n;
  cin >> n >> k;
  for(int i=0;i<k;i++){
    sort(n.begin(),n.end());
    string nn = n;
    int flag = 0;
    int cnt = 0;
    for(int i=0;i<nn.size();i++){
      if(flag) break;
      if(nn[i] == '0') cnt++;
      else flag = 1;
    }
    string nnn = "";
    for(int i = cnt;i<nn.size();i++){
      nnn += nn[i];
    }
    if(nnn == "") nnn = "0";
    ll g1 = stoi(nnn);
    reverse(n.begin(),n.end());
    ll g2 = stoi(n);
    ll f = g2-g1;
    n = to_string(f);
    //cout << n << endl;
  }
  cout << n << endl;
  return 0;
}
