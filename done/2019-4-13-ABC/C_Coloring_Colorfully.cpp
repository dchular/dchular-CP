#include <iostream>

using namespace std;

int cmp_str(string s1, string s2); // stringの違う文字の数,同じ長さ限定

int main(){
  string s;
  cin >> s;
  string s1="",s2="";
  for(int i = 0; i < s.size(); i++){
    s1 += i % 2 + '0';
    s2 += (i+1) % 2 + '0';
  }
  cout << min(cmp_str(s1,s),cmp_str(s2,s));
  return 0;
}

int cmp_str(string s1,string s2){
  int ans = 0;
  for(int i = 0; i < s1.size(); i++){
    ans += max(s1[i],s2[i]) - min(s1[i],s2[i]) ; // 同じだったら0,違ったらその分だけ足す
  }
  return ans;
}
