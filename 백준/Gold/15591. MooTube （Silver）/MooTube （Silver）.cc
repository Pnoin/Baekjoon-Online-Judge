#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> PII;

int n,q,visit[5005]={};
vector <PII> adj[5005];

void dfs(int k, int cur){
  visit[cur]=1;
  for(int i=0; i<adj[cur].size(); i++){
    int nxt=adj[cur][i].first;
    if(adj[cur][i].second < k or visit[nxt]==1){
      continue;
    }
    dfs(k,nxt);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  for(int i=0; i<n-1; i++){
    int x,y,z;
    cin >> x >> y >> z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
  for(int i=0; i<q; i++){
    int x,y,cnt=-1;
    for(int j=1; j<=n; j++){
      visit[j]=0;
    }
    cin >> x >> y;
    dfs(x,y);
    for(int j=1; j<=n; j++){
      if(visit[j]==1){
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
}