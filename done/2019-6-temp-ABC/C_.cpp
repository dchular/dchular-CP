#include <iostream>

using namespace std;

int main(){
  string s;
  int ans = 0,cnt = 0,flag = 0;
  cin >> s;
  int i = 0;
  if(s.size() < 3){cout << '0'; return 0;}
  while(i < s.size()-2){
    if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
      if(cnt == 0) ans+=1;
      else {
        ans += cnt + 1;
        i = i+2;
      }
      s[i] = 'B';
      s[i+1] = 'C';
      s[i+2] = 'A';
      if(i!= 0 && s[i-1] == 'A') i--;
    }
    else {
      if(s[i] == 'A'){
      //  cnt++;
      }
      else cnt = 0;
      i++;
    }
  }
  cout << ans;
  return 0;
}
