#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int n, mx = 0;
  cin >> n;
  pair <int, int> a[105];
  for(int i=0; i<n; i++){
    cin >> a[i].first >> a[i].second;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        if(i==j or j==k or k==i){
          continue; 
        }
        if(a[i].first == a[j].first and a[i].second == a[k].second){
          mx=max(mx,abs(a[i].second-a[j].second)*abs(a[i].first-a[k].first));
        }
      }
    }
  }
  cout << mx;
}