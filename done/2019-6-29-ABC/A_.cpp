#include <iostream>

using namespace std;

int main(){
  string s;
  int cnt = 0;
  cin >> s;
  int c[256] = {0};
  for(int i = 0; i < 4; i ++)
    c[s[i]] ++;
  for(int i = 0; i < 256; i++){
    if(c[i] % 2 == 1){
      cout << "No";
      return 0;
    }
    if(c[i] != 0) cnt++;
  }
  if(cnt != 2)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
