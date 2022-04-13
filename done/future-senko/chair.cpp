#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

// int strtoint(char s[]);
using namespace std;

int int_sort( const void * a , const void * b );
int strtoint(char s[]);
int main(int argc, char *argv[]) {
  int a[10],m = argc - 2;
  for (int i = 1; i < argc-1; i++) {
    a[i-1] = strtoint(argv[i]);
  }
  int L = strtoint(argv[argc-1]);

  int check[10] = {0,0,0,0,0,0,0,0,0,0};
  int ans = 0,now =0;

  qsort(a , m, sizeof(int),int_sort);
  for(int i = 0; i < m; i++){
    if(now + a[i] <= L) now += a[i];
    else{
      now = a[i];
      ans ++;
    }
  }
  if(now != 0) ans++;
  printf("%d",ans);
  return 0;
}

int strtoint(char s[]){
  int ans = 0;
  for(int i = 0; i < strlen(s); i ++){
    ans += s[i] - '0';
    ans *= 10;
  }
  return ans/10;
}

int int_sort( const void * a , const void * b ) {
  if( *( int * )a < *( int * )b ) {
    return -1;
  }
  else
  if( *( int * )a == *( int * )b ) {
    return 0;
  }
  return 1;
}
