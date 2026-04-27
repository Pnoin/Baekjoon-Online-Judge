#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, visit[1005][1005]={}, area=0, peri=0, aa=0, pp=0;
char arr[1005][1005]={};

void dfs(int y, int x) {
  if(y<0 or y>=n or x<0 or x>=n){
    pp++;
    return;
  }
  if(visit[y][x]==1){
    return;
  }
  if(arr[y][x]=='.'){
    pp++;
    return;
  }
  visit[y][x]=1;
  if(arr[y][x]=='#'){
    aa++;
  }
  dfs(y,x+1);
  dfs(y,x-1);
  dfs(y+1,x);
  dfs(y-1,x);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(visit[i][j]==0 and arr[i][j]=='#'){
        dfs(i,j);
        if(area==aa){
          peri=min(peri, pp);
        }
        else if(aa>area){
          area=aa;
          peri=pp;
        }
        aa=0;
        pp=0;
      }
    }
  }
  cout << area  << ' ' << peri;
}