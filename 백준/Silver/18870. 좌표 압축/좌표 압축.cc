#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,q;
  cin >> n;
  vector <pair<int,int>> v;
  for(int i=0; i<n; i++){
    cin >> q;
    v.push_back({q,i});
  }
  sort(v.begin(),v.end());
  vector <pair<int,int>> b; 
  int cnt=0;
  b.push_back({v[0].second, 0});
  for(int i=1; i<n; i++){
    if(v[i].first==v[i-1].first){
      b.push_back({v[i].second, cnt});
    }
    else{
      b.push_back({v[i].second, ++cnt});
    }
  }
  sort(b.begin(), b.end());
  for(int i=0; i<n; i++){
    cout << b[i].second << " ";
  }
}