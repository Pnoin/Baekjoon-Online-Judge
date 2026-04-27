#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[10] = {}, arr[10]={};

void solve(int cur){
  if(cur==m){
    for(int i=0; i<m; i++){
      cout << arr[i] << ' ';
    }
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++){
    arr[cur]=a[i-1];
    solve(cur+1);
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(&a[0], &a[n]);
  solve(0);
}