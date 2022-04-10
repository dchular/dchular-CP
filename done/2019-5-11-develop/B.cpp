#include <iostream>

using namespace std;

int main(){
  int r,g,b,n,ans = 0;
  cin >> r >> g >> b >> n;
  for(int i = 0; i <= n/r;i++){
    for(int j = 0; j <= (n-r*i)/g;j++){
      if( n-r*i-g*j == 0) {
        //cout << i << ' ' << j << ' ' << (n -r*i - g*j) / b << endl;
        ans++;
      }
      if(n -r*i - g*j > 0 && (n -r*i - g*j) % b == 0){
        ans++;
        //cout << i << ' ' << j << ' ' << (n -r*i - g*j) / b << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
