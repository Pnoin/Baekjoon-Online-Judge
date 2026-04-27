#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, visit[100005]={}, ans[100005]={};
vector <int> v[100005];

void dfs(int cur){
  for(int i:v[cur]){
    ans[i]+=ans[cur]; 
    dfs(i);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    int a;
    cin >> a;
    v[a].push_back(i);
  }
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    ans[a]+=b;
  }
  dfs(1);
  for(int i=1; i<=n; i++){
    cout << ans[i] << ' ';
  }
}