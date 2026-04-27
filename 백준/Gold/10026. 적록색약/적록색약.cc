#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, visit[2][105][105] = {};
char arr[2][105][105] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int cur, int y, int x) {
  visit[cur][y][x] = 1;
  for (int i=0; i<4; i++) {
    int yy = y+dy[i];
    int xx = x+dx[i];
    if (xx < 0 or yy < 0 or xx >= n or yy >= n) {
      continue;
    }
    if (visit[cur][yy][xx] == 0 and arr[cur][y][x] == arr[cur][yy][xx]) {
      dfs(cur, yy, xx);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[0][i][j];
      arr[1][i][j]=arr[0][i][j];
      if(arr[1][i][j]=='G'){
        arr[1][i][j]='R';
      }
    }
  }
  for(int t=0; t<2; t++){
    int cnt = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(visit[t][i][j] == 1){
          continue;
        }
        else{
          dfs(t, i, j);
          cnt++;
        }
      }
    }
    cout << cnt << ' ';
  }
}