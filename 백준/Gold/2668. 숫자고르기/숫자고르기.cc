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

int n,m, visit[105]={}, arr[105]={}, cnt=0;
vector <int> ans;

void dfs(int cur, int x){
  visit[cur]=1;
  if(visit[arr[cur]]==1){
    if(arr[cur]==x){
      ans.push_back(arr[cur]);
      cnt++;
    }
  }
  else{
    dfs(arr[cur], x);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n; 
  for(int i=1; i<=n; i++){
    cin >> arr[i];
  }
  for(int i=1; i<=n; i++){
    dfs(i,i);
    memset(visit, 0, sizeof(visit));
  }
  cout << cnt << '\n';
  for(int i=0; i<cnt; i++){
    cout << ans[i] << '\n';
  }
}