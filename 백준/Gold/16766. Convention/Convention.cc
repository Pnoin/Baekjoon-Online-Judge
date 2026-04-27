#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")
using namespace std;

int n, m, c, lo=0, hi=1e9, arr[100005]={};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> c;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(&arr[0],&arr[n]);
  while(true){
    if(lo>hi){
      break;
    }
    int mid=(lo+hi)/2, cnt=1, start=0;
    for(register int i=0; i<n; i++){
      if(i-start<c and arr[i]<=arr[start]+mid){
        continue;
      }
      cnt++;
      start=i;
    }
    if(cnt<=m){
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }
  }
  cout << lo;
}