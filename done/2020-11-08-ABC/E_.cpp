#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int h,w,n,m;
long long ans = 0;
int map[1505][1505];
void check(int xz,int yz);

int main(){
  cin >> h >> w >> n >> m;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    map[a][b] = 1;
    // lightx[i] = a;
    // lighty[i] = b;
  }
  for(int i=0;i<m;i++){
    int c,d;
    cin >> c >> d;
    map[c][d] = 2;
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(map[i][j]!=2)
        check(i,j);
    }
  }
  cout << ans;
  return 0;
}

void check(int xz,int yz){
  int x = xz,y = yz;
  bool flag = false;

  x = xz;y = yz;
  while(1){
    if(x > h) break;
    if(x < 1) break;
    if(map[x][y] == 2) break;
    if(map[x][y] == 1){flag = true;;break;}
    x++;
  }
  if(flag){ans++;return;}

  x = xz;y = yz;
  while(1){
    if(y > w) break;
    if(y < 1) break;
    if(map[x][y] == 2) break;
    if(map[x][y] == 1){flag = true;;break;}
    y++;
  }
  if(flag){ans++;return;}

  x = xz;y = yz;
  while(1){
    if(x > h) break;
    if(x < 1) break;
    if(map[x][y] == 2) break;
    if(map[x][y] == 1){flag = true;;break;}
    x--;
  }
  if(flag){ans++;return;}

  x = xz;y = yz;
  while(1){
    if(y > w) break;
    if(y < 1) break;
    if(map[x][y] == 2) break;
    if(map[x][y] == 1){flag = true;;break;}
    y--;
  }
  if(flag){ans++;return;}
  //cout << "ex: " << xz << ' ' << yz << endl;return;
  return;
}
