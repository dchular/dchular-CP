#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  long long t = 0;
  long long f = 0;
  cin >> s;
  if(s == "AND"){
    t = 1;
    f = 3;
  }
  else{
    t = 3;
    f = 1;
  }
  for(int i=1;i<n;i++){
    cin >> s;
    long long tt,ff;
    if(s == "AND"){
      tt = t;
      ff = f*2 + t;
    }
    else{
      tt = 2*t +f;
      ff = f;
    }
    t = tt;
    f = ff;
    //cout << tt << " " << ff << endl;
  }
  cout << t;
  return 0;
}
