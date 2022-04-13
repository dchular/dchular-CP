#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  string s,t;
  int ans = 0;
  cin >> s >> t;
  for(int i=0; i<=s.size() - t.size(); i++){
    int cnt = 0;
    for(int j=0;  j<t.size();  j++){
      if(s[i+j] == t[j]) cnt++;
    }
    ans = max(ans,cnt);
  }
  cout << t.size() - ans ;
  return 0;
}
