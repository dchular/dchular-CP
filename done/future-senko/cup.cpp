#include <stdio.h>
#include <string.h>

void pour(int i,int j,char map[200][200],char visit[200][200]);
int ans = 0;
int n,m;
int pourflag = 0;
int minwall = 9;

int main(int argc, char *argv[]) {
  //freopen(argv[1],"r",stdin);
  char map[200][200];
  scanf("%d %d",&n,&m);
  for(int i = 0; i < n; i++){
    scanf("%s",map[i]);
  }
  for(int k = 1; k <= 9; k++){
    for(int i=1;i<n-1;i++){
      for(int j=1;j<m-1;j++){
        if(map[i][j] == k+'0'){
          char visit[200][200];
          for(int ii=0;ii<200;ii++)
            for(int jj=0;jj<200;jj++)
              visit[ii][jj] = '0';
          pourflag = 1;
          minwall = 9;
          pour(i,j,map,visit);
          if(pourflag){
            for(int ii = 0; ii < n; ii++){
              for(int jj = 0; jj < m; jj++){
                if(visit[ii][jj] == '1'){
                  map[ii][jj] += (minwall - k);
                  ans+= (minwall - k);
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}

void pour(int i,int j,char map[200][200],char visit[200][200]){
  visit[i][j] = '1';
  //printf("i=%d j=%d pflag=%d\n",i,j,pourflag);
  if(pourflag == 0) return;
  int tmpi[4] = {-1, 0, 0,+1};
  int tmpj[4] = { 0,+1,-1, 0};
  for(int k = 0; k < 4; k++){
    int tempi = tmpi[k];
    int tempj = tmpj[k];
    if(minwall > map[i+tempi][j+tempj] - '0' && map[i+tempi][j+tempj] > map[i][j])
      minwall = map[i+tempi][j+tempj] - '0';
    if(map[i+tempi][j+tempj] <= map[i][j] && visit[i+tempi][j+tempj] == '0'){
      if(i+tempi == 0 || i+tempi == n-1 || j+tempj == 0 || j+tempj == m-1){
        pourflag = 0;
      }
      else pour(i+tempi,j+tempj,map,visit);
    }
  }
}
