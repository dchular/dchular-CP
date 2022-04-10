#include <stdio.h>

int main(int argc, char *argv[]) {
  int num[10]; // vector for counting numbers(1to9)
  for(int i = 0; i < 10;i++) num[i] = 0; // initialize, maybe dont necessary

  // counting numbers
  for(int i = 0; i < strlen(argv[1]); i++){
    int numi = argv[1][i] - '0'; // number of i-th digit
    num[numi] ++;
  }
  // print first digit of answer
  for(int i = 1; i < 10; i++){
    if(num[i] > 0){
      printf("%d",i);
      num[i] --;
      break;
    }
  }
  // print answers
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < num[i] ; j++){
      printf("%d",i);
    }
  }
  printf("\n");
  return 0;
}

// start from 1 to ignore script name; argv[0] will be a name of processing file.
// for (int i = 1; i < argc; i++) {
//   printf ("argv[%i]: %s\n", i, argv[i]);
// }
