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

int n, visit[10005]={}, longdis=0, longp=0, total=0;
vector <pair<int,int>> adj[10005];

void dfs(int cur, int len){
  if(visit[cur]==1){
    return;
  }
  visit[cur]=1;
  if(total<len){
    total=len;
    longp=cur;
  }
  for(int i=0; i<adj[cur].size(); i++){
    dfs(adj[cur][i].first, adj[cur][i].second + len);
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
  for(int i=0; i<n-1; i++){
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
  dfs(1,0);
  total=0;
  memset(visit,0,sizeof(visit));
  dfs(longp,0);
  cout << total;
}
