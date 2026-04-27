#include <iostream>
using namespace std;

int n, m, arr[10]={};

void solve(int cur){
  if(cur==m){
    for(int i=0; i<m; i++){
      cout << arr[i] << ' ';
    }
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++){
    arr[cur]=i;
    solve(cur+1);
  }
}

int main(){
  cin >> n >> m;
  solve(0);
}