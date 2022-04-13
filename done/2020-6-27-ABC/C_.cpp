#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n,m,k,cnt=0;
  int a[300000] = {0};
  int b[300000] = {0};

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }

  int anow = 0,bnow = 0;
  while(k>0){
    int ab_flag = -1; // 0 - a , 1 - b
    if(anow == n && bnow == m) break;
    else if(anow == n && bnow < m) ab_flag = 1;
    else if(anow < n && bnow == m) ab_flag = 0;
    else if(a[anow] + b[bnow] > k) {
      int k1 = k,k2 = k,cnttmp1 = 0,cnttmp2 = 0;
      while(k1 > 0){
        if(k1 < a[anow + cnttmp1] || anow + cnttmp1 >= n) break;
        else{ k1 -= a[anow + cnttmp1]; cnttmp1++;}
      }
      while(k2 > 0){
        if(k2 < b[bnow + cnttmp2] || bnow + cnttmp2 >= m) break;
        else{ k2 -= b[bnow + cnttmp2]; cnttmp2++;}
      }
      if(cnttmp1 > cnttmp2) {cnt += cnttmp1; break;}
      else {cnt += cnttmp2; break;}
    }
    else if(a[anow] >= b[bnow]) ab_flag = 1;
    else if(a[anow] < b[bnow]) ab_flag = 0;
    else cout << "Error No1";

    if(ab_flag == -1) cout << "Error No2";
    int read_time = 0;
    if(ab_flag == 1) {read_time = b[bnow]; bnow++;}
    if(ab_flag == 0) {read_time = a[anow]; anow++;}

    if(k >= read_time) {k -= read_time;cnt++;}
    else break;
  }
  cout << cnt;

  return 0;
}
