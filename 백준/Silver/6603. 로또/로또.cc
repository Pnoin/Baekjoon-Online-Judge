#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[55]={}, op[10]={}, ck[10]={};

void solve(int cur, int start){
  if(cur==6){
    for(int i=0; i<6; i++){
      cout << op[i] << ' ';
    }
    cout << "\n";
  }
  for(int i=start; i<n; i++){
    op[cur]=arr[i];
    solve(cur+1, i+1);
  }
}

int main(){
  while(true){
    cin >> n;
    if(n==0){
      break;
    }
    for(int i=0; i<n; i++){
      cin >> arr[i];
    }
    solve(0,0);
    cout << "\n";
  }
}