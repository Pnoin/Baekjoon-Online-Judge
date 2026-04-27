#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, arr[30][30]={}, visit[30][30]={}, val=0, cnt=0;
char t;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector <int> v;

void dfs(int y, int x) {
  for (int i=0; i<4; i++) {
    int yy = y+dy[i];
    int xx = x+dx[i];
    if (xx < 0 or yy < 0 or xx >= n or yy >= n){
      continue;
    } 
    if (visit[yy][xx] == 0 and arr[yy][xx] == 1) {
      visit[yy][xx] = 1;
      cnt++;
      dfs(yy, xx);
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
      cin >> t;
      if(t=='1'){
        arr[i][j]=1;
      }
      else{
        arr[i][j]=0;
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(visit[i][j]==1 or arr[i][j]==0){
        continue;
      }
      visit[i][j]=1;
      cnt=1;
      dfs(i,j);
      v.push_back(cnt);
      val++;
    }
  }
  sort(v.begin(), v.end());
  cout << val << "\n";
  for(int i=0; i<v.size(); i++){
    cout << v[i] << "\n";
  }
}