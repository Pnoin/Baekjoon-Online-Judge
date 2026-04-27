#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,visit[1005]={},val=0;
vector <int> v[1005];

void dfs(int cur){
  visit[cur]=1;
  for(int i=0; i<v[cur].size(); i++){
    int nxt=v[cur][i];
    if(visit[nxt]==0){
      dfs(nxt);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    if(visit[i]==1){
      continue;
    }
    dfs(i);
    val++;
  }
  cout << val;
}