#include <iostream>

using namespace std;

int main(){
  int n,a,b,c,d;
  string s;
  cin >> n >> a >> b >> c >> d;
  cin >> s;

  if(c > d){
    int flag = 0;
    int flag2 = 0;
    if(s[b] == '.' && s[b-2] == '.') flag = 1;
    else if(s[b] == '.' && s[b+1] == '.') flag = 1;
    else if(s[d-2] == '.' && s[d] == '.') flag = 1;
    else{
      int i = b-1;
      while(s[i] != '#' && i < n) i++;
      if(i == n){
        cout << "No";
        return 0;
      }
      int j = d-1;
      while(s[j] != '#' && d > 0) j--;
      if(d-1 - j >= 2) flag = 1;
      else{
        int cnt = 0;
        while(i < j){
          i++;
          if(s[i-1] == '#'){
            if(cnt >= 3){
              flag = 1;
              if(cnt >= 4){
                flag2 = 1;
                break;
              }
            }
            else
              cnt = 0;
          }
          else cnt++;
        }
      }
    }
    if(flag == 0){
      cout << "No";
      return 0;
    }
    if(flag){
      if(flag2 == 0)
        n--;
    }
  }
  for(int i = 0 ; i < n*100 ; i ++){
    if( b == d && a == c){
      cout << "Yes";
      return 0;
    }
    if(b < d){
      if(d - b == 1 || d - b == 2){
        b = d;
        continue;
      }
      else if(s[b+1] == '.'){
        b += 2;
        continue;
      }
      else if(s[b] == '.'){
        b ++;
        continue;
      }
      else break;
    }
    if(a < c){
      if(c - a == 1 || c - a == 2){
        a = c;
        continue;
      }
      else if(s[a+1] == '.'){
        a += 2;
        continue;
      }
      else if(s[a] == '.'){
        a ++;
        continue;
      }
      else break;
    }
  }
  if( b == d && a == c){
    while(1){;}
  }
  cout << "No";
  return 0;
}
