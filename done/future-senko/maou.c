#include <stdio.h>

int main(int argc, char *argv[]) {
  // start from 1 to ignore script name; argv[0] will be a name of processing file.
  // for (int i = 1; i < argc; i++) {
  //   printf ("argv[%i]: %s\n", i, argv[i]);
  // }
  int hp = atoi(argv[1]);
  int a = atoi(argv[2]);
  int b = atoi(argv[3]);
  int cnt = 1,wflag = 0;
  hp -= a;
  if(hp <= 0) wflag = 1;
  else if(b >= a) wflag = 0;
  else{
    wflag = 1;
    int diff = a-b;
    cnt += hp / diff;
    if(hp % diff != 0) cnt++;
  }
  if(wflag){
    printf("YES\n%d\n",cnt);
  }
  else printf("NO\n");
  return 0;
}
