#include <stdio.h>
#include <string.h>

int answer = 0;
void search(int n,int k,char s[],int cnt);
int count(char s[]);
int strtoint(char s[]);

int main(int argc, char *argv[]) {
  FILE *fp;
  char str[1005];
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("%s file not open!\n", argv[1]);
    return -1;
  }
  fgets(str, 1005, fp);
  int i=0;
  int n=0,k=0;
  while(str[i] != ' '){
    n+=str[i]-'0';
    n*=10;
    i++;
  }
  n/=10;
  i++;
  while(str[i] != '\n'){
    k += str[i] - '0';
    k*=10;
    i++;
  }
  k/=10;
  fgets(str, 1005, fp);
  fclose(fp);
  search(n,k,str,count(str));
  printf("%d",answer);
  return 0;
}

void search(int n,int k,char s[],int cnt){
  //printf("%s\n",s);
  if(cnt == n){
    answer = n;
    return;
  }
  if(k == 0){
    if(cnt > answer)
      answer = cnt;
    return;
  }
  if(answer > cnt + k*3) return;
  for(int i = 0; i < n; i++){
    if(s[i] == 'S'){
      int fleft = 0,fright = 0;
      s[i] = '.';
      if(i >= 1){
        if(s[i-1] == 'S'){
          s[i-1] = '.';
          fleft = 1;
        }
      }
      if(i < n-1){
        if(s[i+1] == 'S'){
          s[i+1] = '.';
          fright = 1;
        }
      }
      search(n,k-1,s,cnt + 1 + fright + fleft);
      s[i] = 'S';
      if(fleft) s[i-1] = 'S';
      if(fright) s[i+1] = 'S';
    }
  }
  return;
}

int count(char s[]){
  int cnt = 0;
  for(int i = 0; i< strlen(s); i++){
    if(s[i] == '.') cnt++;
  }
  return cnt;
}
