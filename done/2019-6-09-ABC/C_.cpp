#include <iostream>

using namespace std;

int main(){
  int n,m;
  long long a[100000];
  cin >> n >> m;
  for(int i = 0 ; i < 100000; i++) a[i] = 0;
  for(int i = 0 ; i < m; i++){
    int temp ;
    cin >> temp;
    a[temp-1] = -1;
  }

  for(int i = 0; i < n;i++){
    if(a[i] != -1){
      if(i == 0) a[i] = 1;
      else if(i == 1) {
        if(a[0] != -1) a[i] = 2;
        else a[i] = 1;
      }
      else{
        if(a[i-2] != -1) a[i] += a[i-2] % 1000000007;
        a[i] = a[i] % 1000000007;
        if(a[i-1] != -1) a[i] += a[i-1] % 1000000007;
        a[i] = a[i] % 1000000007;
      }
    }
  }
  cout << a[n-1];
  return 0;
}
