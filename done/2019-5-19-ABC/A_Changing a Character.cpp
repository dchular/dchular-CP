#include <iostream>

using namespace std;

int main(){
  int n,k;
  string s;
  cin >> n >> k >> s;
  s[k-1] = s[k-1]-'A'+'a';
  cout << s;
  return 0;
}
