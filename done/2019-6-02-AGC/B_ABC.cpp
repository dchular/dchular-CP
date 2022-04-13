#include <iostream>

using namespace std;

int main(){
  string s;
  long long ans = 0,cnt = 0,flag = 0;
  cin >> s;
  int i = 0;
  for(int i = 0;i < s.size();i ++) {
		if(s[i] == 'A') cnt++;
		else if(s[i] == 'B' && s[i + 1] == 'C') ans += cnt,i ++;
		else cnt = 0;
	}
  cout << ans;
  return 0;
}
