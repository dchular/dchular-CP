#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  double ans = 0;
  for(int i=n-1;i>=1;i--){
    ans += (double)n/i;
  }
  cout <<  std::fixed << setprecision(10) << ans;
}
