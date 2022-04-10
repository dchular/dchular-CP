#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
long long n,k;
long long p[5005],c[5005];
long long color_map[5005] = {0};
long long ans = -9223372036854775807;

void coloring_calc(int i,int color){
  long long group[10005] = {0};
  for(int i=0;i<5005;i++) group[i] = 0;
  group[0] = c[i];
  color_map[i] = color;
  int size = 1;
  int now = i;
  while(1){
    now = p[now];
    if(now == i) break;
    color_map[now] = color;
    group[size] = c[now];
    size++;
  }
  //  cout << "color:" << color << endl;
  //  for(int i = 0; i < size; i++){
  //    cout << group[i] << ' ';
  //  }
  //  cout << endl;

  long long gsum = 0,sum = 0;
  for(int i = 0; i < size; i ++){
    gsum += group[i];
  }
  int flag = 1;
  if(gsum > 0 && k >= size){
    sum += gsum * (k/size);
    flag = 0;
    k = k % size;
  }
  ans = max(sum,ans);

  for(int i = 0; i < size;i++)
    group[i + size] = group[i];

  for(int j = flag; j <= k; j++){
    if(j > size) break;
    long long realsum = sum;

    for(int i = 0; i < size; i++){
      realsum = sum;
      for(int l = i; l < i+j; l++){
        realsum += group[l];
      }
      ans = max(realsum,ans);
      //cout << "realsum = " << realsum << ' ' << i << ' ' << j << endl;
    }
  }
  return;
}

int main(){
  int color = 1;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> p[i];
    p[i] -=1;
  }
  for(int i = 0; i < n; i++){
    cin >> c[i];
  }

  for(int i = 0; i < n ; i ++){
    if(color_map[i] == 0) {coloring_calc(i,color);color++;}
  }

  cout << ans;

  return 0;
}
