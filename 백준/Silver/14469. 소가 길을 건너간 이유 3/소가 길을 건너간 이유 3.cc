#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, total=0;
  cin >> n;
  pair <int, int> a[105];
  for(int i=0; i<n; i++){
    cin >> a[i].first >> a[i].second;
  }
  sort(&a[0], &a[n]);
  for(int i=0; i<n; i++){
    if(a[i].first < total){
      total+=a[i].second;
    }
    else{
      total=a[i].first+a[i].second;
    }
  }
  cout << total;
}