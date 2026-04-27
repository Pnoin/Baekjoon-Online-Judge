#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, visit[100005]={},ans[100005]={};
vector <int> v[100005];

void dfs(int cur){
  visit[cur]=1;
  for(int i:v[cur]){
    if(visit[i]==1){
      continue;
    }
    ans[i]=cur; 
    dfs(i);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n-1; i++){
    int a,b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  for(int i=2; i<=n; i++){
    cout << ans[i] << "\n";
  }
}