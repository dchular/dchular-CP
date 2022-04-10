#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
char map[30][30];

int main(){
  int n,m;
  int cnt = 0;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> map[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int x[10] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};
      int y[10] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
      cnt = 0;
      for(int k=0;k<9;k++){
        int xx = i+x[k],yy = j+y[k];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m){
          if(map[xx][yy] == '#')
            cnt++;
        }
      }
      cout << cnt;
    }
    cout << endl;
  }
  return 0;
}
