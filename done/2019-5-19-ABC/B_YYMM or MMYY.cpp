#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;
  if(s.size() < 4) {printf("NA");return 0;}

  int a=0,b=0;
  a = s[1]-'0' + (s[0]-'0') *10;
  b = s[3]-'0' + (s[2]-'0') *10;

  if(a >= 0 && a <= 99 && b > 0 && b <= 12){
    if (a > 0 && a<=12 && b >= 0 && b <=99){
      printf("AMBIGUOUS");
      return 0;
    }
    else{
      printf("YYMM");
      return 0;
    }
  }
  int t=a;
  a=b;b=t;
  if(a >= 0 && a <= 99 && b > 0 && b <= 12){
    if (a > 0 && a<=12 && b >= 0 && b <=99){
      printf("AMBIGUOUS");
      return 0;
    }
    else{
      printf("MMYY");
      return 0;
    }
  }
  printf("NA");
  return 0;
}
