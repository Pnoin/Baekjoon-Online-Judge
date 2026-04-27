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

int n,m,visit[105][105]={}, arr[105][105]={},val[105][105]={};
queue <pair<int,int>> q;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(int y, int x){
  q.push({y,x});
  visit[y][x]=1;
  val[y][x]=1;
  while(!q.empty()){
    int yy=q.front().first, xx=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int nxty=yy+dy[i];
      int nxtx=xx+dx[i];
      if(nxty<1 or nxtx<1 or nxtx>m or nxty>n){
        continue;
      }
      if(visit[nxty][nxtx]==0 and arr[nxty][nxtx]==1){
        val[nxty][nxtx]=val[yy][xx]+1;
        q.push({nxty,nxtx});
        visit[nxty][nxtx]=1;
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
	  for(int j=1; j<=m; j++){
	    char c;
	    cin >> c;
	    if(c=='1'){
	      arr[i][j]=1;
	    }
	    else{
	      arr[i][j]=0;
	    }
	  }
	}
  bfs(1,1);	
  cout << val[n][m];
}
