#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a,int b);
int chose(int a,int b,int c);

int main(){
  int N,A[100000];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  if(N == 1){
    cout << A[0];
  }
  else if(N == 2){
    cout << max(A[0],A[1]);
  }
  else{
    //sort(A,A+N);
    int ans = gcd(A[1],A[2]);
    for(int i=1;i<N;i++){
      ans = gcd(ans,A[i]);
    }// 0 habuku
    int temp = gcd(A[0],A[2]);
    for(int i=3;i<N;i++){
      temp = gcd(temp,A[i]);
    }// 1 habuku
    ans = max(temp,ans);
    for(int i=2;i<N;i++){
      temp = gcd(A[0],A[1]);
      for(int j=0;j<N;j++){
        if(j == i) continue;
        temp = gcd(temp,A[j]);
        if(temp < ans) break;
        if(j == 1000) break;
      }
      ans = max(temp,ans);
    }
    cout << ans;
  }
  return 0;
}

int gcd(int a, int b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int gcd3(int a,int b,int c){
  return gcd(gcd(a,b),c);
}
