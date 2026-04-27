#include <algorithm>
#include <iostream>
using namespace std;

int n, arr[10]={}, c[10]={};

void solve(int cur){
  if(cur==n){
    for(int i=0; i<n; i++){
      cout << arr[i] << ' ';
    }
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++){
    if(c[i]==1){
      continue;
    }
    c[i]=1;
    arr[cur]=i;
    solve(cur+1);
    c[i]=0;
  }
}
int main(){
  cin >> n;
  solve(0);
}

