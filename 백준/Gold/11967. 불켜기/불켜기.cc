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

int n,m,visit[105][105]={}, cnt=1,ck[105][105]={};
queue <pair<int,int>> q;
vector <pair<int,int>> adj[105][105];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(int y, int x){
  q.push({y,x});
  visit[y][x]=1;
  while(!q.empty()){
    int yy=q.front().first, xx=q.front().second;
    q.pop();
    for(int i=0; i<adj[yy][xx].size(); i++){
      int nxty=adj[yy][xx][i].first, nxtx=adj[yy][xx][i].second;
      if(ck[nxty][nxtx]==0){
        ck[nxty][nxtx]=1;
        cnt++;
        for(int j=0; j<4; j++){
          if(nxty+dy[j]<1 or nxty+dy[j]>n or nxtx+dx[j]<1 or nxtx+dx[j]>n){
            continue; 
          }
          if(visit[nxty+dy[j]][nxtx+dx[j]]==1){
            visit[nxty][nxtx]=1;
            q.push({nxty,nxtx});
          }
        }
      }
    }
    for(int j=0; j<4; j++){
      if(yy+dy[j]<1 or yy+dy[j]>n or xx+dx[j]<1 or xx+dx[j]>n){
        continue; 
      }
      if(ck[yy+dy[j]][xx+dx[j]]==1 && visit[yy+dy[j]][xx+dx[j]]==0){
        visit[yy+dy[j]][xx+dx[j]]=1;
        q.push({yy+dy[j],xx+dx[j]});
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
	  int x,y,a,b;
	  cin >> x >> y >> a >> b;
	  adj[x][y].push_back({a,b});
	}
	ck[1][1]=1;
	bfs(1,1);
	cout << cnt;
}
