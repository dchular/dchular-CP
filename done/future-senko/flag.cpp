#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // start from 1 to ignore script name; argv[0] will be a name of processing file.
  int wstate = 0;
  int rstate = 0;
  int winflag =1;
  char ru[] = "RU", rd[] = "RD", wu[] = "WU", wd[] = "WD";
  //printf("w=%d r=%d wf=%d\n",wstate,rstate,winflag);
  for (int i = 1; i < argc; i++) {
    //printf ("argv[%i]: %s\n", i, argv[i]);
    if(!strcmp(argv[i], ru)){
      //printf("ru\n");
      if(rstate == 0) rstate = 1;
      else winflag = 0;
    }
    else if(!strcmp(argv[i], rd)){
      //printf("rd\n");
      if(rstate == 1) rstate = 0;
      else winflag = 0;
    }
    else if(!strcmp(argv[i], wu)){
      //printf("wu\n");
      if(wstate == 0) wstate = 1;
      else winflag = 0;
    }
    else if(!strcmp(argv[i], wd)){
      //printf("wd\n");
      if(wstate == 1) wstate = 0;
      else winflag = 0;
    }
    //printf("w=%d r=%d wf=%d\n",wstate,rstate,winflag);
  }
  if(winflag){
    printf("Simon\n");
    if(rstate) printf("U");
    else printf("D");
    if(wstate) printf("U\n");
    else printf("D\n");
  }
  else printf("Alice\n");
  return 0;
}
