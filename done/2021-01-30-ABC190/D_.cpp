#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
  long long n;
  cin >> n;
  n *= 2;
  long long ans = 0;
  vector <long long> di = divisor(n);
  for(int i=0;i<di.size();i++) {
    long long temp = n;
    temp /= di[i];
    temp += 1-di[i];
    if(temp %2 == 0) ans++;
  }
  cout << ans;
  return 0;
}
