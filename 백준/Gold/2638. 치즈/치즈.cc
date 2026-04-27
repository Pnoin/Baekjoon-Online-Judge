#include <iostream>
#include <algorithm>
#include <queue>
#pragma GCC optimize("O3")
using namespace std;

int n, m, cheese[105][105]={}, cnt=0, total=0, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue <int> q1;
queue <int> q2;

void nxt(int y, int x) {
  if(cheese[y][x]==1 or cheese[y][x]==-1){
    return;
  }
  cheese[y][x]=-1;
  for (int i=0; i<4; i++) {
    int yy = y+dy[i], xx = x+dx[i];
    if (xx < 0 or yy < 0 or xx >= m or yy >= n) {
      continue;
    }
    nxt(yy,xx);
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> cheese[i][j];
    }
  }
  nxt(0,0);
  while(true){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(cheese[i][j]==1){
          cnt=0; 
          for(int k=0; k<4; k++){
            int yy = i+dy[k];
            int xx = j+dx[k];
            if(cheese[yy][xx]==-1){
              cnt++;
            }
          }
          if(cnt>1){
            q1.push(i);
            q2.push(j);
          }
        }
      }
    }
    if(q1.empty()){
      break;
    }
    while(!q1.empty()){
      int y=q1.front(), x=q2.front();
      q1.pop();
      q2.pop();
      cheese[y][x]=-1;
      for(int i=0; i<4; i++){
        int yy = y+dy[i], xx = x+dx[i];
        if(cheese[yy][xx]==0){
          nxt(yy,xx);
        }
      }
    }
    total++;
  }
  cout << total;
}