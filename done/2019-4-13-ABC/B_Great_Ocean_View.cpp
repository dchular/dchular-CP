#include <iostream>

using namespace std;

int main(){
  int N,H[20];
  int max_h = -1,ans=0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> H[i];
    max_h = max(max_h,H[i]);
    if(H[i] >= max_h)
      ans++;
  }
  cout << ans;
  return 0;
}
