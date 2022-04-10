#include <iostream>

using namespace std;

int main(){
  int n,a[100000];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  while(1){
    int mx = -1;
    int index = -1;
    for(int i=0;i+1<n;i++){
      if(a[i]+a[i+1] < -1*a[i] + -1*a[i+1]){
        if(mx < -1*a[i] + -1*a[i+1]){
          mx = -1*a[i] + -1*a[i+1];
          index = i;
        }
      }
    }
    cout << index << endl;
    if(index != -1){
      a[index] *=-1;
      a[index+1] *=-1;
    }
    else break;
  }
  unsigned long ans = 0;
  for(int i=0;i<n;i++){
    ans +=a[i];
  }
  cout << ans;
  return 0;
}
