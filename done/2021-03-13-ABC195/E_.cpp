#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
typedef long long ll;

int main(){
  ll n;
  string s,x;
  string t = "";
  cin >> n >> s >> x;
  int dp[200005][7] = {0};
  dp[n][0] = 1;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<7;j++){
      int t1 = j*10 + 0;
      t1 %= 7;
      int t2 = j*10 + s[i] - '0';
      t2 %= 7;
      if(x[i] == 'T'){
        if(dp[i+1][t1] != 0 || dp[i+1][t2] != 0){
          dp[i][j] = 1;
        }
      }
      if(x[i] == 'A'){
        if(dp[i+1][t1] != 0 && dp[i+1][t2] != 0){
          dp[i][j] = 1;
        }
      }
    }
  }
  if(dp[0][0] == 1) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
  return 0;
}
