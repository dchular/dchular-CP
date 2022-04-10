#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <atcoder/segtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using S = int;
S op(S a, S b){return a^b;}
S e(){return 0;}

int main(){
    int n;
    int q;
    cin >> n >> q;
    std::vector<S> a;
    for(int i=0;i<n;i++){
      int b;
      cin >> b;
      a.push_back(b);
    }
    atcoder::segtree<S, op,e> seg(a);
    for(int i=0;i<q;i++){
      int t,x,y;
      cin >> t >> x >> y;
      if(t == 2) cout << seg.prod(x-1,y) << endl;
      if(t == 1) seg.set(x-1, seg.get(x-1) ^ y);
    }
}
