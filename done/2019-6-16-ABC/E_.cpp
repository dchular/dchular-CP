#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;
typedef pair<int, int> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
    return firstElof.first < secondElof.first;
}

int main(){
  int n,m,b,c;
  vector<P>  a;
  cin >> n >> m;

  for(int i = 0; i < n; i ++){
    int t;
    cin >> t;
    a.push_back(make_pair(t,1));
  }
  sort(a.begin(),a.end(),pairCompare);


  for(int i = 0; i < m; i ++){

    cin >> b >> c;
    vector<P>::iterator index;
    int id = lower_bound(a.begin(), a.end(), make_pair(c, 0), pairCompare) - a.begin();
    int iindex = distance(a.begin(),a.begin()+id);

    if(b >= iindex) {
      for(int j=0;j<iindex) erase(a.begin()+j);
      a.insert(a.begin(),make_pair(c,b));
    }
    else {
      for(int j = 0; j < b; j++) erase(a.begin()+j)
        iter_swap(a.begin() + j, a.begin() + j-b);
      }
    }
  }
  long long sum =0;
  for(int i=0;i<n;i++){
    sum += a[i].first;
  }
  cout << sum;

  return 0;
}
