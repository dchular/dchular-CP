#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,k;
  int a[200005];
  cin >> n >> k;

  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  for(int i = k ;i < n; i++){
    if(a[i] > a[i-k]) cout << "Yes";
    else cout << "No";

    if(i != n + 1) cout << endl;
  }
  return 0;
}
