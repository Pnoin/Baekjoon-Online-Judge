#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w,e,visit[20005]={},ck=0;
vector <int> v[20005];

void dfs(int cur, int colour){
  visit[cur]=colour;
  for(int k=0; k<v[cur].size(); k++){
    int nxt=v[cur][k];
    if(visit[nxt]!=0){
      if(visit[nxt]==visit[cur]){
        ck=1; 
        return;
      }
    }
    else{
      if(colour==1){
        dfs(nxt,2);
      }
      else if(colour==2){
        dfs(nxt,1);
      }
    }
    if(ck==1){
      return;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    cin >> w >> e;
    for(int j=0; j<=w; j++){
      visit[j]=0;
    }
    for(int j=1; j<=w; j++){
      v[j].clear();
    }
    for(int j=0; j<e; j++){
      int a,b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    ck=0;
    for(int j=1; j<=w; j++){
      if(visit[j]==0){
        dfs(j,1);
      }
    }
    if(ck==1){
      cout << "NO" << '\n';
    }
    else{
      cout << "YES" << '\n';
    }
  }
}