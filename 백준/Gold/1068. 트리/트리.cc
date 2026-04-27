#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;

int n,m,visit[55]={}, cnt=0, start=-2, temp[55]={};
vector <int> adj[105];

void dfs(int cur){
  visit[cur]=1;
  if(adj[cur].size()==0){
    cnt++;
    return;
  }
  for(int i=0; i<adj[cur].size(); i++){
    if(visit[adj[cur][i]]==0){
      dfs(adj[cur][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> temp[i];
  }
  cin >> m;
  for(int i=0; i<n; i++){
    if(i==m){
      adj[100].push_back(i);
      continue;
    }
    if(temp[i]!=-1){
      adj[temp[i]].push_back(i);
    }
    else{
      start=i;
    }
  }
  if(start==-2){
    cout << 0;
    return 0;
  }
  dfs(start);
  cout << cnt;
}

