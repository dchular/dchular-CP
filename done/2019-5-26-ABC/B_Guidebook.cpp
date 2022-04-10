#include <iostream>

using namespace std;

bool cmp(pair<string, pair<int,int> > a, pair<string, pair<int,int> > b){
  if(a.first != b.first){
    return a.first < b.first;
  }
  else {
    return a.second.second > b.second.second;
  }
}

int main(){
  int n;
  pair<string, pair<int,int> > list[100];
  string s;
  int p;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s >> p;
    list[i] = make_pair(s, make_pair(i+1,p));
  }
  std::sort(list,list + n, cmp);
  for(int i = 0; i < n; i++){
    cout << list[i].second.first << endl;
  }
  return 0;
}
