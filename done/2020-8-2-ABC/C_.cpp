#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

string int_to_string(int k){
  string ans = "";
  while(k){
    ans += k%10 + '0';
    k/=10;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int check_string(string str){
  int flag = 1;
  for(int i=0; i<str.size(); i++){
    if(str[i] != '1') {flag = 0;break;}
  }
  return flag;
}

string string_plus(string str1,string str2){
  reverse(str1.begin(),str1.end());
  reverse(str2.begin(),str2.end());
  int tmp = str1.size() - str2.size();
  for(int i = 0 ; i < tmp; i++){
    str2 += '0';
  }
  string ans = "";
  int carry = 0;
  for(int i=0;i<str1.size();i++){
    int a1 = str1[i] - '0';
    int a2 = str2[i] - '0';
    int a3 = a1+a2+carry;
    if(a3<10){
      ans += a3 + '0';
      carry = 0;
    }
    else {
      ans += a3%10 + '0';
      carry = 1;
    }
  }
  if(carry == 1) ans += '1';
  reverse(ans.begin(),ans.end());
  return ans;
}

void solve(int k){
  string now = int_to_string(k);
  string kk = int_to_string(k);
  int count = 1;
  while(1){
  int flag = check_string(now);
  if(flag == 1) break;

  now = string_plus(now,kk);
  count++;
  }
  int ans = now.size();
  cout << ans << endl;
  return;
}

int main(){
  int k;
  cin >> k;
  if(k%2 == 0 || k%5 == 0) cout << "-1" << endl;
  else {
    //cout << int_to_string(k) << endl;
    //cout << check_string(int_to_string(k)) << endl;
    //cout << string_plus("99","1") << endl;
    solve(k);
  }
  return 0;
}
