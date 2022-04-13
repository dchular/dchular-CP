#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;



int main(){
  int n;
  string s;
  cin >> n >> s;
  int ans = n;
  int cntwhite = 0;
  for(int i=0;i<n;i++){
    if(s[i] == '.') cntwhite++;
  }
  int cntw = 0,cntb = 0;
  ans = n - cntwhite;
  ans = min(ans,cntwhite);
  for(int i=0;i<n;i++){
    if(s[i] == '.') cntw ++;
    else cntb++;
    int tmp = cntb + (cntwhite - cntw);
    ans = min(ans,tmp);
    //cout << tmp << endl;
  }
  cout << ans;
  return 0;
}
