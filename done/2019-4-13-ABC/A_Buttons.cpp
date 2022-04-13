#include <iostream>

using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  if(A != B)
    cout << max(A,B) * 2 - 1;
  else
    cout << A * 2;
  return 0;
}
