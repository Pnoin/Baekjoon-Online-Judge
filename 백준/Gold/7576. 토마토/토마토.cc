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

int n,m, arr[1005][1005]={},cnt=0, val[1005][1005]={}, mn=0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
queue <pair<int,int>> q;

void bfs(){
  while(!q.empty()){
    int cury=q.front().first, curx=q.front().second,temp2=0;
    q.pop();
    for(int i=0; i<4; i++){
      int nxty=dy[i]+cury, nxtx=dx[i]+curx;
      if(nxty<0 or nxtx<0 or nxty>=m or nxtx>=n){
        continue;
      }
      if(arr[nxty][nxtx]==0){
        q.push({nxty,nxtx});
        arr[nxty][nxtx]=1;
        val[nxty][nxtx]=val[cury][curx]+1;
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(arr[i][j]==1){
        q.push({i,j});
      }
    }
  }
  bfs();
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j]==0){
        cout << -1;
        return 0;
      }
    }
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(val[i][j]>mn){
        mn=val[i][j];
      }
    }
  }
  cout << mn;
}
