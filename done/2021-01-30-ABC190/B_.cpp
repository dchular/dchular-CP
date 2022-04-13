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
  int n,x;
  cin >> n >> x;
  vector<int> ve;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(a != x) ve.push_back(a);
  }
  for(int i=0;i<ve.size();i++) cout << ve[i] << ' ';
  cout << endl;
  return 0;
}
