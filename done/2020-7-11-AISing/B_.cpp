#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,cnt=0;
  int a[101];
  cin >> n;

  for(int i=1;i<=n;i++){
    cin >> a[i];
    if(i%2 == 1 && a[i] %2 == 1) cnt++;
  }
  cout << cnt;
  return 0;
}
