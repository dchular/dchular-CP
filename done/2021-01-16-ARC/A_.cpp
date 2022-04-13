#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  int n;
  long long a[200005];
  long long b[200005];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  long long c = a[0];
  long long aa = 0;
  long long bb = 0;

  for(int i=0;i<n;i++){
    aa = max(aa,a[i]);
    if(b[i] > bb){
      bb = b[i];
      c = bb*aa;
    }
    else{
      c = max(c, b[i] * aa);
    }
    cout << c << endl;
  }
  return 0;
}
