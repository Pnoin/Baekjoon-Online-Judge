#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,m,visit[2005]={}, ans=0;
vector <int> adj[2005];

void dfs(int cur, int cnt){
	if(cnt==5){
		ans=1;
		return;
	}
	visit[cur]=1;
	for(int i=0; i<adj[cur].size(); i++){
		if(visit[adj[cur][i]]==0){
			dfs(adj[cur][i], cnt+1);
		}
	}
	visit[cur]=0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m; 
	for(int i=0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0; i<n; i++){
		memset(visit,0,sizeof(visit));
		dfs(i,1);
	}
	cout << ans;
}