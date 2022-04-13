#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  string start = s;
  int flag = 1;
  sort(s.begin(),s.end());
  do{
    //cout << s << endl;
    string r = s;
    reverse(r.begin(), r.end());
    if(start != s && r != start){
      cout << s << endl;
      flag = 0;
      break;
    }
  }while(next_permutation(s.begin(),s.end()));
  if(flag) cout << "None";
  return 0;
}
