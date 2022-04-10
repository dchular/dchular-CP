#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,l[15];
  cin >> n;
  cin >> l[0];
  int mx = l[0];
  int index = 0;
  int sum = l[0];
  for(int i=1;i<n;i++){
    cin >> l[i];
    if(mx < l[i]){
      index = i;
      mx = l[i];
    }
    sum += l[i];
  }
  if(sum - mx > mx) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
