#include <iostream>
#include <algorithm>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long int ll;

int n, arr[2][100005]={};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int ck=0;
  for(int i=0; i<2; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(i==1){
        if(arr[0][j]!=arr[i][j]){
          ck=1;
        }
      }
    }
  }
  if(ck==0){
    cout << "POSSIBLE";
  }
  else{
    for(int i=2; i<n; i++){
      if(arr[1][i]>arr[1][i-1] && arr[1][i-1]>arr[1][i-2]){
        cout << "POSSIBLE";
        return 0;
      }
      else if(arr[1][i]<arr[1][i-1] && arr[1][i-1]<arr[1][i-2]){
        cout << "POSSIBLE";
        return 0;
      }
    }
    cout << "IMPOSSIBLE";
  }
}