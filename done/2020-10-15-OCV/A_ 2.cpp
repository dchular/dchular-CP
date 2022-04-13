#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  long long sum1=0,sum2=0;
  long long cnt1=0,cnt2=0;
  int flag = 1;
  for(int i=0;i<n;i++){
    long long tmp;
    cin >> tmp;
    if(tmp + sum1 == 0 && flag){
      sum1 = 1;
      cnt1 += 1;
    }
    else if(tmp + sum1 == 0 && flag == 0){
      sum1 = -1;
      cnt1 += 1;
    }
    else if(tmp + sum1 > 0 && flag){
      sum1 += tmp;
    }
    else if(tmp + sum1 < 0 && flag == 0){
      sum1 += tmp;
    }
    else if(tmp + sum1 > 0 && flag == 0){
      cnt1 += abs((tmp + sum1)) + 1;
      sum1 = -1;
    }
    else if(tmp + sum1 < 0 && flag){
      cnt1 += abs((tmp + sum1)) + 1;
      sum1 = 1;
    }

    if(tmp + sum2 == 0 && flag){
      sum2 = -1;
      cnt2 += 1;
    }
    else if(tmp + sum2 == 0 && flag == 0){
      sum2 = 1;
      cnt2 += 1;
    }
    else if(tmp + sum2 < 0 && flag){
      sum2 += tmp;
    }
    else if (tmp + sum2 > 0 && flag){
      cnt2 += abs((tmp + sum2)) + 1;
      sum2 = -1;
    }
    else if(tmp + sum2 > 0 && flag == 0){
      sum2 += tmp;
    }
    else if(tmp + sum2 < 0  && flag == 0){
      cnt2 += abs((tmp + sum2)) + 1;
      sum2 = 1;
    }

    if(flag) flag = 0;
    else flag = 1;
  }
  cout << min(cnt1,cnt2) << endl;
  return 0;
}
