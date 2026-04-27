#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n, total=0, min=999999999;
  cin >> n; 
  pair <int, int> a[100005];
  for(int i=0; i<n; i++){
    cin >> a[i].first >> a[i].second;
  }
  for(int i=0; i<n-1; i++){
    total+=abs(a[i].first-a[i+1].first)+abs(a[i].second-a[i+1].second);
  }
  for(int i=0; i<n-2; i++){
    int copy=total;
    copy-=abs(a[i].first-a[i+1].first)+abs(a[i].second-a[i+1].second)+abs(a[i+1].first-a[i+2].first)+abs(a[i+1].second-a[i+2].second);
    copy+=abs(a[i].first-a[i+2].first)+abs(a[i].second-a[i+2].second);
    if(copy<min){
      min=copy;
    }
  }
  cout << min;
}