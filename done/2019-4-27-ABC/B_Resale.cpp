#include <iostream>

using namespace std;

int main(){
  int N,V[20],C[20],ans = 0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> V[i];
  }
  for(int i=0;i<N;i++){
    cin >> C[i];
  }

  for(int i = 0; i < N; i++){
    if(V[i] > C[i])
      ans+= V[i] - C[i];
  }
  cout << ans;
  return 0;
}
