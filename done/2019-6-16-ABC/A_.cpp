#include <iostream>

using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  long long d = 0,cnt = 0;
  for (int i = 0;i < n; i++){
    int temp;
    cin >> temp;
    d += temp;
    if(d <= x)
      cnt ++;
  }

  cout << cnt + 1 ;
  return 0;
}
