#include <iostream>
#include <vector>
using namespace std;

int n,m,a,b,visit[255]={},cnt=0;
vector <int> v[255];

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
    if(visit[i]==0){
      cout << i << "\n";
      cnt=1;
    }
  }
  if(cnt==0){
    cout << 0;
  }
}