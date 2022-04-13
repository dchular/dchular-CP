#include <iostream>

using namespace std;

int main(){
  string s,t;
  int cnt = 1;
  cin >> s >> t;
  for(int i=0;i<s.size();i++)
    if(s[i] == t[i]) cnt++;
  cout << cnt;
  return 0;
}
