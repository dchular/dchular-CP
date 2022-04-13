#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int  main(){
  long long  n,m,k,cnt=0;
  long long a[300000] = {0};
  long long  b[300000] = {0};

  int debug;
  cin >> n >> m >> k;
  for(long long  i = 0; i < n; i++){
    cin >> a[i];
    //a[i] = 1000000000;
    if ( i == 0 ) continue;
    if(2147483646-a[i] < a[i-1]) a[i] = 2147483646;
    else if(i!=0) a[i] += a[i-1];
  }
  //cout << "HERE" << endl;

  for(long long  i = 0; i < m; i++){
    cin >> b[i];
    //b[i] = 1000000000;
    if ( i == 0) continue;
    if(2147483646-b[i] < b[i-1]) b[i] = 2147483646;
    else if(i!=0) b[i] += b[i-1];
  }
  //cout << "HERE2" << endl;

  long long nn=n,mm=m;
  for(long long  i = 0; i < n; i++){
    if (a[i] > k) {nn = i;break;}
  }
  for(long long  i = 0; i < m; i++){
    if (b[i] > k) {mm = i;break;}
  }
  //if(mm == 0) mm = m;
  //if (nn == 0) nn = n;
  long long jj = mm-1;
  for(long long  i = 0; i < nn; i++){
    for(long long  j = jj; j >= 0; j--){
      //cout << i << ' ' << j << endl;
      if(2147483646 - a[i] < b[j]) continue;
      if(a[i] + b[j] <= k) {jj = j;cnt = max(cnt,i+j+2);break;}
    }
  }

  //cout << "HERE3" << endl;

  for(long long  i = nn-1; i >= 0; i --){
    if(a[i] <= k) {cnt = max(cnt,i+1);break;}
  }
  for(long long  i = mm-1; i >= 0; i --){
    if(b[i] <= k) {cnt = max(cnt,i+1);break;}
  }

  cout << cnt;
}
