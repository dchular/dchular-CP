#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  double ans = 0;
  for(int i = 1; i <= n; i ++){
    double t = (double) k / (double) i; // 10/
    if(t <= 1){
      ans += 1 / (double) n;
    //  printf("%0.9lf\n",ans);
    }
    else{
      double tt = log2(t); // 3.??
      int ttt = tt; // 3 ?
      if( double(ttt) != tt) ttt++;
      ans += 1 / (n * pow(2,ttt));
      //printf("%d %lf %lf %d %0.9lf %d\n",i,t,tt,ttt,ans,n * (int)pow(2,ttt));
    }
  }
  printf("%0.12lf\n",ans);
  return 0;
}
