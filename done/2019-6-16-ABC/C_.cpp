#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

double pi = 3.1415926535;

double s4(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
  double ans = 0;
  ans += abs( (x1-x2) * (y1+y2) );
  ans += abs( (x2-x3) * (y2+y3) );
  ans += abs( (x3-x4) * (y3+y4) );
  ans += abs( (x4-x1) * (y4+y1) );
  return ans / 2;
}

int main(){
  int w,h,x,y;
  int cnt = 0;
  double ans = w*h;
  double s = w*h;
  cin >> w >> h >> x >> y;
  for(int i = 0; i < 179; i++){
    double k = cos(pi / 180 * i);
    double b = y - k * x;
    double s1,s2;
    if(k == 0){
      if (w/2 == x) {
        if (ans == w*h /2) cnt++;
        else {cnt = 1; ans = w*h/2;}
      }
      continue;
    }
    int flag1=0, flag2=0, flag3=0, flag4=0;
    if(b >= 0 && b <= h){ // x = 0
      flag1 = 1;
    }
    if( (0 - b) / k >= 0  && (0 - b) / k <= w){ // y = 0
      flag2 = 1;
    }
    if( (k*w + b) >= 0 && (k*w + b) <= h){  // x = w
      flag3 = 1;
    }
    if( (h - b) / k >= 0  && (h - b) / k <= w){ // y = h
      flag4 = 1;
    }


    cout << flag1 << flag2 << flag3 << flag4 << ' ' << k << "*x+" << b << endl;
    if(flag1 && flag2){
      s1 = b * ( (0 - b) / k ) / 2;
      s2 = s - s1 ;
      if(min(s1,s2) == ans) cnt++;
      else if(min(s1,s2) < ans) {ans = min(s1,s2);cnt = 1;}
    }
    if(flag1 && flag3){
      s1 = s4(0,0,w,0,0,b,w,(k*w + b));
      s2 = s - s1 ;
      if(min(s1,s2) == ans) cnt++;
      else if(min(s1,s2) < ans) {ans = min(s1,s2);cnt = 1;}
    }
    if(flag1 && flag4){
      s1 = (h-b) * ( (h - b) / k ) /2;
      s2 = s - s1 ;
      if(min(s1,s2) == ans) cnt++;
      else if(min(s1,s2) < ans) {ans = min(s1,s2);cnt = 1;}
    }
    if(flag2 && flag3){
      s1 = (w - ((0 - b) / k)) * (k*w + b) / 2;
      s2 = s - s1 ;
      if(min(s1,s2) == ans) cnt++;
      else if(min(s1,s2) < ans) {ans = min(s1,s2);cnt = 1;}
    }

    if(flag2 && flag4){
      s1 = s4(0,0,0,h,(0 - b) / k,0,(h - b) / k,h);
      s2 = s - s1 ;
      if(min(s1,s2) == ans) cnt++;
      else if(min(s1,s2) < ans) {ans = min(s1,s2);cnt = 1;}
    }

    if(flag3 && flag4){
      s1 = (h - (k*w + b)) * (w - ( (h - b) / k) ) / 2;
      s2 = s - s1 ;
      if(min(s1,s2) == ans) cnt++;
      else if(min(s1,s2) < ans) {ans = min(s1,s2);cnt = 1;}
    }
  }

  cout << ans << endl << cnt;
  return 0;
}
