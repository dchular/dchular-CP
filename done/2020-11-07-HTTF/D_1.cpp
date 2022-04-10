#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
int h,w;
int ch,cw,dh,dw;
char tmpmap[1005][1005];
int map[1005][1005];

void coloring(int x,int y,int color){
  map[x][y] = color;
  if(x > 0){
    if(map[x-1][y] == 0)
      coloring(x-1,y,color);
  }
  if(x < h-1){
    if(map[x+1][y] == 0)
      coloring(x+1,y,color);
  }
  if(y > 0){
    if(map[x][y-1] == 0)
      coloring(x,y-1,color);
  }
  if(y < w-1){
    if(map[x][y+1] == 0)
      coloring(x,y+1,color);
  }
}

int main(){
  cin >> h >> w;
  cin >> ch >> cw >> dh >> dw;
  ch -= 1;dh -= 1;
  cw -= 1;dw -= 1;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w ; j++){
      cin >> tmpmap[i][j];
      if(tmpmap[i][j] == '.') map[i][j] = 0;
      else map[i][j] = -1;
    }
  }

  int color = 1;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(map[i][j] == 0) {coloring(i,j,color);color++;}
    }
  }
  color = color - 1;
  int tmp1[20] = {-2,-2,-2,-2,-2,-1,-1,-1,-1, 0, 0,+1,+1,+1,+1,+2,+2,+2,+2,+2};
  int tmp2[20] = {-2,-1, 0,+1,+2,-2,-1,+1,+2,-2,+2,-2,-1,+1,+2,-2,-1, 0,+1,+2};
  bool connection[color+5][color+5];
  for(int i=0;i<=color;i++)
    for(int j=0;j<=color;j++)
      connection[i][j] = 0;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      for(int k=0;k<20;k++){
        int x = i+tmp1[k];
        int y = j+tmp2[k];
        if(x >= 0 && x < h && y >= 0 && y < w){
          if(map[i][j] != -1 && map[i][j] != map[x][y]){
              int color1 = map[i][j];
              int color2 = map[x][y];
              connection[color1][color2] = 1;
              connection[color2][color1] = 1;
          }
        }
      }
    }
  }

  // cout << color << endl;
  // for(int i=1;i<=color;i++){
  //   for(int j=1;j<=color;j++){
  //     cout << connection[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  int ans = 0;
  if(map[ch][cw] == map[dh][dw]){cout << ans; return 0;}
  if(map[ch][cw] == -1 || map[dh][dw] == -1){cout << "-1"; return 0;}
  int memo[color+5];
  for(int i=1;i<=color;i++) memo[i] = -1;
  memo[map[ch][cw]] = 0;
  queue <int> que;
  que.push(map[ch][cw]);

  while(que.size()) {
    int now = que.front();
    que.pop();
    if(now == map[dh][dw]) break;
    for(int i=1;i<=color;i++){
      //cout << "now and i = " <<now << ' ' << i <<  ' ' <<connection[now][i] << endl;
      if(connection[now][i] == 1 && memo[i] == -1){
        que.push(i);
        memo[i] = memo[now] + 1;
      }
    }
  }

  cout << memo[map[dh][dw]];
  return 0;
}
