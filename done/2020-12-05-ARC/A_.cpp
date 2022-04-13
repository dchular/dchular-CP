#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  long long n;
  int prime[15] = {0};
  int plist[10] = {2,3,5,7,11,13,17,19,23,29};
  cin >> n;
  long long ans = 1;
  for(int i=n;i>=2;i--){
    int tmp = i;
    for(int i=0;i<10;i++){
      int tmp2 = 0;
      while(tmp % plist[i] == 0){
        tmp2++;
        tmp /= plist[i];
      }
      if(prime[i] < tmp2) prime[i] = tmp2;
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<prime[i];j++){
      ans *=plist[i];
    }
  }
  cout << ans + 1;
  // for(int i=2;i<n;i++){
  //   cout << i << " " << ans % i << endl;
  // }
  return 0;
}
