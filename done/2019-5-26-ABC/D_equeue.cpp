#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;
int n,k;
int v[50];
deque<int> v;
int max_sum = 0;

void solve(int cnt,deque<int> v,int sum){
  if(cnt == 0){
    if(sum > max_sum)
      max_sum = sum;
  }
  int temp = v.begin();
  v.pop_front();
  solve(cnt--,v,sum + temp);
  v.push_front(temp);

}

int main(){
  cin >> n >> k;

  for(int i = 0; i < n; i ++){
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  solve(k,v,0);
  for(int i = 0; i < k ; i++){

  }

  cout << sum;
  return 0;
}
