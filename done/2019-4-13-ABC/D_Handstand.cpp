#include <iostream>

using namespace std;

string change_str(string s){ // 0と1がいくつあるか数える 11110001-> 431
  string ans;
  char oz = s[0]; // 何を数えてるか
  int cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == oz){ // 1111 0 なら0まで
      cnt ++;
      if(i == s.size()-1)
        ans += cnt + '0';
    }
    else { // 1111 0の0のとこ
      if(oz == '1') oz = '0';
      else oz = '1';
      ans += cnt + '0'; // 1111 0 なら ans -> 4
      cnt = 1; // 1111 0 なら0のとこのため
      if(i == s.size()-1)
        ans += cnt + '0';
    }
  }
  return ans;
}

int main(){
  string s;
  int n,k,ans = -1;
  cin >> n >> k >> s;

  string str = change_str(s);
  cout << str;
  if(s[0] == '0'){
    int cnt = 0;
    for(int i = 0; i < min(k * 2,(int)str.size()); i++){
      cnt += str[i] - '0';
      cout << "test 1- " << cnt << endl;
    }
    ans = max(ans,cnt);
  }
  if(s[s.size()-1] == '0'){
    int cnt = 0;
    for(int i = str.size() - 1; i >= max(0,(int)str.size() - k*2); i--){
      cnt += str[i] - '0';
      cout << "test 2- " << cnt << endl;
    }
    ans = max(ans,cnt);
  }
  int flag = 0;
  int temp;
  if(s[0] == '0') temp = 1;
  else temp = 0;
  for(int i = temp; i < str.size(); i+=2){
    if(flag == 0){
      int cnt = 0;
      for(int j = i; j < min((int)str.size(),i + 2 * k+1);j++){
        cnt += str[j] - '0';
        cout << "test 3- " << cnt << endl;
      }
      ans = max(ans,cnt);
    }
  }
  cout << ans;
  return 0;
}
