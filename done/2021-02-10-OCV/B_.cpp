#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;

int main(){
  int n;
  long long sumA,sumB;
  cin >> n;
  int a[10005],b[10005];
  for(int i=0;i<n;i++){
    cin >> a[i];
    sumA += a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
    sumB += b[i];
  }
  sort(a,a+n);
  sort(b,b+n);

  long long sousaA = sumB - sumA,sousaB = sumB-sumA;

  if(sousaA < 0){
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    //cout << "A = " << a[i] << " B = " << b[i] << endl;
    if(a[i] < b[i]){
      sousaA -= (b[i] - a[i]) /2 + 1;
      sousaB -= (b[i] - a[i]) %2;
    }
    if(a[i] > b[i]){
      sousaB -= b[i] - a[i];
    }
    //cout << "sousaA = " << sousaA << " sousaB = " << sousaB << endl;
  }
  if(sousaA < 0 || sousaB < 0) cout << "No" << endl;
  else if((sousaA - sousaB) % 2 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
