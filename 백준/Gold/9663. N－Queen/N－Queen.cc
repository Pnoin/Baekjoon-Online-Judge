#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, cnt=0, arr[20]={};

bool check(int y){
  for(int i=0; i<y; i++){
    if(arr[y]==arr[i] or y-i==abs(arr[y]-arr[i])){
      return false;
    }
  }
  return true;
}

void solve(int x){
  if(x==n){
    cnt++;
    return;
  }
  for(int i=0; i<n; i++){
    arr[x]=i;
    if(check(x)){
      solve(x+1);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  solve(0);
  cout << cnt;
}