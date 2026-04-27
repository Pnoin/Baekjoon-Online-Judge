#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n,arr[2][200005]={}, cnt[2][200005]={}, total=0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin >> n;
  arr[0][0]=0;
  arr[1][0]=0;
  for(int i=0; i<2; i++){
    for(int j=1; j<=n; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<2; i++){
    for(int j=1; j<=n; j++){
      if(arr[i][j]==1){
        if(j%2==0){
          cnt[i][j]++;
          int nxtx=j+1,prvx=j-1;
          if(nxtx>n){
            cnt[i][j]++;
          }
          else if(nxtx<=n){
            if(arr[i][nxtx]==0){
              cnt[i][j]++;
            }
          }
          if(arr[i][prvx]==0){
            cnt[i][j]++;
          }
        }
        else{
          int nxtx=j+1,prvx=j-1;
          if(nxtx>n){
            cnt[i][j]++;
          }
          else if(nxtx<=n){
            if(arr[i][nxtx]==0){
              cnt[i][j]++;
            }
          }
          if(arr[i][prvx]==0){
            cnt[i][j]++;
          }
          if(i==0){
            if(arr[1][j]==0){
              cnt[i][j]++;
            }
          }
          else{
            if(arr[0][j]==0){ 
              cnt[i][j]++;
            }
          }
        }
      }
      total+=cnt[i][j];
    }
  }
  cout << total;
}
