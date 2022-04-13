#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
string s;

void migi(int x){
  for(int j=0;j<x;j++){
    for(int i=0;i<s.size()-1;i++){
      if(s[i+1] == '#'){
        s[i] = '#';
      }
    }
  }
}
void hidari(int x){
  for(int j=0;j<x;j++){
    for(int i=1;i<s.size();i++){
      if(s[i-1] == '#'){
        s[i] = '#';
      }
    }
  }
}

int main(){
  int n;
  int x=-1,y=-1;
  cin >> n >> s;
  for(int i=0;i<s.size();i++){
    if(s[i] == '#'){
      x = i;
      break;
    }
  }
  for(int i=s.size()-1;i>=0;i--){
    if(s[i] == '#'){
      y = s.size() - (i+1);
      break;
    }
  }
  migi(x);
  hidari(y);
  //cout << s << endl;
  int cnt = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '.'){
      int j = 0;
      while(s[i+j] == '.'){
        if(i + j == s.size()) break;
        j++;
      }
      //cout << i << ' ' << j << endl;
      cnt = max(cnt,j);
    }
  }
  cout << x+cnt << ' ' << y << endl;
  return 0;
}
