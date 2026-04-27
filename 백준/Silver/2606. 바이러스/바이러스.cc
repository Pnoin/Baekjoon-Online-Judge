#include <iostream>
#include <vector>
using namespace std;

int n,m,a,b,cnt=0,visit[105]={};
vector <int> v[105];

void dfs(int cur){
  visit[cur]=1; 
  for(int i=0; i<v[cur].size(); i++){
    int q=v[cur][i];
    if(visit[q]==0){
      dfs(q);
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  for(int i=1; i<=n; i++){
    if(visit[i]==1){
      cnt++;
    }
  }
  cout << cnt-1;
}