#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[10]={}, a[10]={}, c[10]={};

void solve(int x, int y){
  if(y==m){
    for(int i=0; i<m; i++){
      cout << a[i] << ' ';
    }
    cout << "\n";
    return;
  }
  for(int i=x; i<n; i++){
    if(c[i]==0){
      c[i]=1;
      a[y]=arr[i];
      solve(i+1, y+1);
      c[i]=0;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(&arr[0], &arr[n]);
  solve(0,0);
}