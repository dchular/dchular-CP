#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
struct train{
  int b;
  int t;
  int k;
};

int main(){
  int n,m,x,y;
  vector<struct train> map[100005];
  cin >> n >> m >> x >> y;

  for(int i=0;i<n;i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    struct train tmp;
    tmp.b = b;
    tmp.t = c;
    tmp.k = d;
    map[a].push_back(tmp);
  }
  queue<struct train> que;
  que.push_back(x,0)
  return 0;
}
