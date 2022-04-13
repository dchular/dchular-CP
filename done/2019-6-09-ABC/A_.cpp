#include <iostream>

using namespace std;

int main(){
  int p,q,r;
  cin >> p >> q >> r;

  if (p >= q && p >= r) cout << q + r;
  else if (q >= p && q >= r) cout << p + r;
  else if (r >= q && r >= p) cout << q + p;
  return 0;
}
