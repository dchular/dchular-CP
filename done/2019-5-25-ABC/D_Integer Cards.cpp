#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;
typedef pair<int, int> P;

int main(){
  int n,m,b,c;
  vector<int>  a;
  cin >> n >> m;

  for(int i = 0; i < n; i ++){
    int t;
    cin >> t;
    a.push_back(t);
  }
  sort(a.begin(),a.end());

  for(int i = 0; i < m; i ++){

    //cout << endl << i+1 << "回目 vectorは: " ;
    //for(int i=0;i<n;i++) cout << a[i] << ' ';
    //cout << endl;
    cin >> b >> c;
    vector<int>::iterator index;
    index = lower_bound(a.begin(),a.end(),c);
    //cout << "場所は: " << distance(a.begin(),index) << ' '  << endl;
    int iindex = distance(a.begin(),index);
    for(int j=0;j<b;j++){
      if(a[j] < c) a[j] = c;
      else break;
    }

    if(b >= iindex) continue;
    else {
      for(int j = b; j < iindex; j++){
        //cout << "kokodayo : ";
        //cout << "b:" << b << " iindex" << iindex << " j:" << j << endl;
        iter_swap(a.begin() + j, a.begin() + j-b);
      }
    }
  }
  long long sum =0;
  for(int i=0;i<n;i++){
    sum += a[i];
  }
  cout << sum;
  return 0;
}
