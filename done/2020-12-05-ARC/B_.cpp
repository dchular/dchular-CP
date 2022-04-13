#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;

int check(string s){
  string ss = s.substr(0,3);
  int tmp = 0;
  int ans = 0;
  if(ss == "110"){
    tmp = 0;
    ans = 0;
  }
  if(ss == "101"){
    tmp = 2;
    ans = 1;
  }
  if(ss == "011"){
    tmp = 1;
    ans = 2;
  }
  string str = "110";
  for(int i = tmp ; i < s.size();i++){
    if(s[i] != str[(i-tmp) % 3]) return -1;
  }
  return ans + 1;
}

int main(){
  int n;
  long long MX = 30000000000;
  long long AA = 10000000000;
  string t;
  cin >> n >> t;
  if(t == "1"){
    cout << AA * 2 << endl;
    return 0;
  }
  else if( t == "0" || t == "10" || t == "11"){
    cout << AA << endl;
    return 0;
  }
  else if(t == "01"){
    cout << AA-1 << endl;
    return 0;
  }
  else if ( t.size() < 3){
    cout << "0" << endl;
    return 0;
  }
  else{
    int start = check(t);
    if(start == -1){
      cout << "0" << endl;
      return 0;
    }
    else {
      // long long ans = 0;
      // int j = 0;
      //
      // while(start + n -1  + j <= 3000){
      //   ans ++;
      //   j += 3;
      // }
      // cout << ans << endl;
      // cout << (3000 - n + 1 - start ) /3 + 1;
      long long aaa = MX - n + 1 - start;
      cout << aaa / 3 + 1  << endl;

    }
  }
  return 0;
}
