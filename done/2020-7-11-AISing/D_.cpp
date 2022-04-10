#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

char rev(char c){
  if (c=='1') return '0';
  else return '1';
}

int popcount(string x){
  int cnt = 0;
  for(int i=0;i<x.size();i++){
    if(x[i] == '1') cnt++;
  }
  return cnt;
}

string int_str(int n){
  string tmp="";
  while(n>0){
    if(n % 2 == 0) tmp+= '0';
    else tmp+='1';
    n/=2;
  }
  string tmp2 = tmp;
  for(int i=0;i<tmp.size();i++){
    tmp2[i] = tmp[tmp.size() - 1 - i];
  }
  return tmp2;
}

string divide(string x,string y){
  for(int i = 0; i + y.size() <= x.size() ; i++){
    //cout << i << ' ' << x << endl;
    if(x[i] == '0') continue;

    int flag = 0;
    for(int ii = i; ii <= i+y.size() ; ii++){
      if(x[ii] < y[ii-i]) {flag = 1;break;}
    }
    if(flag ==1 && i+y.size() == x.size()) continue;
    if(flag == 1) {x[i] = '0';}
    for(int j=0; j < y.size(); j++){
      if(y[j] == '1' && x[i+j+flag] == '1') x[i+j+flag] = '0';
      else if(y[j] == '1' && x[i+j+flag] == '0') x[i+j+flag] = '1';
      else if(y[j] == '0') continue;
      else cout << "Error No1 << endl;";
    }
  }
  if(x.size() == y.size()){
    for(int j=0; j < y.size(); j++){
      if(y[j] == '1' && x[j] == '1') x[j] = '0';
      else if(y[j] == '1' && x[j] == '0') x[j] = '1';
      else if(y[j] == '0') continue;
    }
  }
  string tmp = "";
  int flagg=0;
  for(int i=0;i<y.size();i++){
    if(x[x.size() - y.size() + i] == '1') flagg = 1;
    if(flagg)
      tmp += x[x.size() - y.size() + i];
  }
  return tmp;
}

void solve(string x,int flag){
  //cout << x << ' ' << popcount(x) << ' ' << int_str(popcount(x)) << divide(x,int_str(popcount(x)))<< endl;
  int cnt = 0;
  while(1){
    x = divide(x,int_str(popcount(x)));
    cnt++;
    //cout << x.size();
    if(x == "1") {cnt ++; break;}
    string tmp = "";
    if(x == tmp) break;
  }
  if(flag) cout << cnt;
  else cout << cnt << endl;
  return;
}



int main(){
  int n;
  string x;
  cin >> n >> x;

  //cout << divide("11","10");

  for(int i=0;i<n;i++){
    x[i] = rev(x[i]);
    int flag = 0;
    if(i == n-1) flag = 1;
    solve(x,flag);
    x[i] = rev(x[i]);
  }
  return 0;
}
