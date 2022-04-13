#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <atcoder/lazysegtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value^b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int n;
    int q;
    cin >> n >> q;
    std::vector<S> a(n);
    for(int i=0;i<n;i++){
      int b;
      cin >> b;
      a[i] = S{b,1};
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    for(int i=0;i<q;i++){
      int t,x,y;
      cin >> t >> x >> y;
      if(t == 2) cout << "1" << endl;
      if(t == 1) seg.set(x, S{(seg.get(x).value )^y,1}) << endl;
    }
}
