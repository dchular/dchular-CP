#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll k;
string s,t;

int point(string a,string b){
  int aa[10] = {0};
  int bb[10] = {0};
  ll scoreA = 0,scoreB = 0;
  for(int i=0;i<a.size();i++){
    aa[a[i] - '0'] ++;
    bb[b[i] - '0'] ++;
  }
  for(int i=1;i<=9;i++){
    ll ten = 1;
    for(int j=0;j<aa[i];j++){
      ten *= 10;
    }
    scoreA += ten * i;
    ten = 1;
    for(int j=0;j<bb[i];j++){
      ten *= 10;
    }
    scoreB += ten * i;
  }
  //cout << scoreA << endl << scoreB << endl;
  if(scoreA > scoreB) return 1;
  else return 0;
}

double solve(int i,int j){
  string handA = s;
  string handB = t;
  handA[4] = i+'0';
  handB[4] = j+'0';

  int suji[10] = {0};
  for(int i=0;i<5;i++){
    suji[handA[i] - '0'] ++;
    suji[handB[i] - '0'] ++;
  }

  if(suji[i] > k || suji[j] > k) return 0;

  if(point(handA,handB) == 0) {
    //cout << handA << handB << endl;
    return 0;
  }




  double ans = 0;
  double waru = k*9 - 8;
  // cout << (k-suji[i]) << endl;
  // cout << (k-suji[j]) << endl;
  // cout << waru << endl;
  //cout << handA << ' ' << handB << ' ';
  if(i != j)
    ans = (k-suji[i] + 1) * (k-suji[j] + 1) / waru / (waru-1);
  else
    ans = (k-suji[i] + 2) * (k-suji[j] + 1) / waru / (waru-1);
  //cout << ans << endl;
  return ans;
  //cout << (k-suji[i]) * (k-suji[j]) / waru / (waru-1) << endl;
  //return (k-suji[i]) * (k-suji[j]) / waru / (waru-1);
}



int main(){
  double ans = 0;
  cin >> k >> s >> t;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      ans += solve(i,j);
    }
  }
  cout << ans;
  return 0;
}
