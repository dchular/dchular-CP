#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  string n;
  int sum = 0;
  int map[3] = {0,0,0};
  cin >> n;
  for(int i=0;i<n.size();i++){
    sum += n[i] - '0';
    map[(n[i] - '0' ) %3] ++;
  }
  if(sum % 3 == 0) cout << "0" << endl;
  else if(n.size() == 1) cout << "-1" << endl;
  else {
    if(map[sum % 3] > 0) cout << "1" << endl;
    else{
      if(sum % 3 == 1){
        if(map[2] < 2) cout << "-1" << endl;
        else if(map[2] > 2) cout << "2" << endl;
        else if(n.size() > 2) cout << "2" << endl;
        else cout << "-1" << endl;
      }
      else if(sum%3 == 2){
        if(map[1] < 2) cout << "-1" << endl;
        else if(map[1] > 2) cout << "2" << endl;
        else if(n.size() > 2) cout << "2" << endl;
        else cout << "-1" << endl;
      }
    }
  }
  return 0;
}
