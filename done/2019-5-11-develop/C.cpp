#include <iostream>

using namespace std;

int find(string s){
  int ans = 0,flag = 0;
  for(int i = 0 ; i < s.size(); i++){
    if(flag){
      if(s[i] == 'B')
         ans++;
      flag = 0;
    }
    if(s[i] == 'A') flag = 1;
  }
  return ans;
}

void dp(int mas[10],int n,int m){
  if(n == 0){
    temp =
  }
  for(int i=0;i<n;i++){
    if(mas[i] == 0)
  }
}

int main(){
  int n,ans = 0,a=0,b=0,c=0;
  string s;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> s;
    ans+= find(s);
    if(s[s.size()-1] == 'A') a++;
    if(s[0] == 'B') b++;
    if(s[0] == 'B' && s[s.size()-1] == 'A') c++;
  }
  ans += min(a,b);
  if(c == a && c == b && c > 0)
    ans-=1;
  cout << ans;
  return 0;
}
