#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>

using namespace std;
int placex[100],placey[100];
int map[20][20];
int nowx = 0,nowy = 0;
int nxt = 0;
stack<int> sta;
string ans = "";

void solve1();
void solve11();
void solve2();
void solve3();
void go(int targetx,int targety);
int checkup();
int checkdown();

int main(){
  srand(time(NULL));
  for(int i=0;i<20;i++)
    for(int j=0;j<20;j++)
      map[i][j] = -1;

  for(int i=0;i<100;i++){
    cin >> placex[i] >> placey[i];
    // while(1){
    //   int a = rand()%20;
    //   int b = rand()%20;
    //   if(map[a][b] == -1){
    //     placex[i] = a;
    //     placey[i] = b;
    //     break;
    //   }
    // }
    int y = placex[i],x = placey[i];
    map[x] [y] = i;
  }
  solve11();
  solve2();
  solve3();
  cout << ans;
  return 0;
}

void solve3(){
  while(nxt != 100){
    go(placex[nxt],placey[nxt]);
    if(map[nowx][nowy] == nxt){
      ans += "I";
      nxt++;
    }
    else{
      cout << "Error No 2";
    }
  }
}

void solve2(){
  if(nowy >= 11) go(19,10);
  int tmpy = nowy;
  while(!sta.empty()){
    int card = sta.top();
    sta.pop();
    int tmpx = 0;
    if((card / 10 ) % 2 == 0){
      tmpx = 19 - card % 10;
    }
    else
      tmpx = 10 + card % 10;
    go(tmpx, tmpy + card/10);
    if(map[nowx][nowy] == -1){
      ans += "O";
      map[nowx][nowy] = card;
      placex[card] = nowx;placey[card] = nowy;
    }
    else {
      cout << "Error No1";
    }
  }
}

void go(int targetx,int targety){
  while(1){
    if(targetx == nowx && targety == nowy) break;
    if(targetx > nowx){
      ans += "R";
      nowx ++;
    }
    if(targetx < nowx){
      ans += "L";
      nowx --;
    }
    if(targety > nowy){
      ans += "D";
      nowy ++;
    }
    if(targety < nowy){
      ans += "U";
      nowy --;
    }
  }
}
void solve1(){
  while(1){
    bool flag;
    if(nowx % 2 == 0){
      flag = true;
    }
    else flag = false;

    while(1){
      if(map[nowx][nowy] != -1){
        sta.push(map[nowx][nowy]);
        ans += "I";
        placex[map[nowx][nowy]] = -1;
        placey[map[nowx][nowy]] = -1;
        map[nowx][nowy] = -1;
      }
      if( (nowy == 19 && flag) || (nowy == 0 && !flag)) break;
      if(flag){
        ans += "D";
        nowy ++;
      }
      else {
        ans += "U";
        nowy--;
      }
    }
    if(nowx == 19) break;
    nowx ++;
    ans += "R";
  }
}

void solve11(){
  while(1){
    while(1){
      if(map[nowx][nowy] != -1){
        sta.push(map[nowx][nowy]);
        ans += "I";
        placex[map[nowx][nowy]] = -1;
        placey[map[nowx][nowy]] = -1;
        map[nowx][nowy] = -1;
      }
      int up = checkup(),down = checkdown();
      if(up == -1 && down == -1) break;
      if(up == -1){
        ans += "D";
        nowy ++;
      }
      else if(down == -1){
        ans += "U";
        nowy --;
      }
      else if( abs(up - nowy) > abs(down - nowy) ){
        ans += "D";
        nowy ++;
      }
      else{
        ans += "U";
        nowy --;
      }
      // int aaa;
      // cin >> aaa;
      // cout << ans << endl;
      // cout << "x = " << nowx << " y = " << nowy << endl;
      // cout << "checkup,checkdown = " << up << ' ' << down << endl;
    }
    //cout << "x = " << nowx << " y = " << nowy << endl;
    if(nowx == 19) break;
    nowx ++;
    ans += "R";
  }
}

int checkup(){
  int i=1;
  int ans = -1;
  while(nowy - i >=0){
    if(map[nowx][nowy - i] != -1){
      ans = nowy - i;
    }
    i++;
  }
  return ans;
}

int checkdown(){
  int i=1;
  int ans = -1;
  while(nowy + i < 20){
    if(map[nowx][nowy + i] != -1){
      ans = nowy+i;
    }
    i++;
  }
  return ans;
}
