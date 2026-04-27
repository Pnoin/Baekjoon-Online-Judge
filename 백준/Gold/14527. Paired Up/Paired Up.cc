#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int,int>> v;
int mx=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int q,w;
    cin >> q >> w;
    v.push_back(pair<int,int>(w,q));
  }
  sort(v.begin(),v.end());
  int x=0, y=n-1, mx=0;
  while(true){
    if(x>y){
      break;
    }
    int a=min(v[x].second, v[y].second);
    if(x==y){
      a/=2;
    }
    mx=max(mx, v[x].first+v[y].first);
    v[x].second-=a;
    v[y].second-=a;
    if(v[x].second==0){
      x++;
    }
    if(v[y].second==0){
      y--;
    }
  }
  cout << mx;
}