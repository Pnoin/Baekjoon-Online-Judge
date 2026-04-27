#include <iostream>
#include <algorithm>
using namespace std;

int hi[10005]={}, lo[10005]={}, total=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> hi[i];
  }
  sort(&hi[0], &hi[n]);
  for(int i=0; i<m; i++){
    cin >> lo[i];
  }
  sort(&lo[0], &lo[m]);
  int c=-1;
  for(int i=0; i<n; i++){
    for(int j=c+1; j<m; j++){
      if(hi[i]<=lo[j]){
        break;
      }
      else{
        total++;
        c=j;
        break;
      }
    }
  }
  cout << total+n;
}