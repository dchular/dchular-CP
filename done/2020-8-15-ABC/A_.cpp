#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,ans = 0;
  int l[105];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> l[i];
  }

  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        if(i == j || i == k || j == k) continue;
        int a,b,c;
        a = l[i]; b=l[j]; c=l[k];

        if(a == b || a == c || b == c) continue;
        if(a + b < c || a + c < b || b + c < a) continue;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
