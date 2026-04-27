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

int n,m,v,visit[1005]={};
vector <int> adj[1005];
queue <int> q;

void dfs(int cur){
  visit[cur]=1;
  cout << cur << ' ';
  sort(adj[cur].begin(), adj[cur].end());
  for(int i=0; i<adj[cur].size(); i++){
    int nxt=adj[cur][i];
    if(visit[nxt]==0){
      dfs(nxt);
    }
  }
}

void bfs(int cur){
  q.push(cur);
  visit[cur]=1;
  cout << cur << ' ';
  while(!q.empty()){
    int num=q.front();
    q.pop();
    for(int nxt: adj[num]){
      if(visit[nxt]==0){
        q.push(nxt);
        visit[nxt]=1;
        cout << nxt << ' ';
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> v;
	for(int i=0; i<m; i++){
	  int x,y;
	  cin >> x >> y;
	  adj[x].push_back(y);
	  adj[y].push_back(x);
	}
	dfs(v);
	cout << '\n';
	memset(visit,0,sizeof(visit));
	bfs(v);
}
