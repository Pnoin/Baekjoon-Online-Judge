#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> PII;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visit[105][105]={}, cnt=0;
set <PII> s[105][105];
vector <PII> v(10005);
int n,k,r;

void dfs(int y, int x) {
  visit[y][x] = 1;
  for (int i=0; i<4; i++) {
    int yy = y+dy[i];
    int xx = x+dx[i];
    if (xx < 1 || yy < 1 || xx > n || yy > n || visit[yy][xx] == 1 || s[y][x].count({yy,xx}) > 0) {
      continue;
    }
    dfs(yy,xx);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> r;
  for(int i=0; i<r; i++){
    int a,b,c,d;
    cin >> a >> b>> c>> d;
    s[a][b].insert({c,d});
    s[c][d].insert({a,b});
  }
  for(int i=0; i<k; i++){
    cin >> v[i].first >> v[i].second;
  }
  for(int i=0; i<k; i++){
    memset(visit, 0, sizeof(visit));
    dfs(v[i].first, v[i].second);
    for(int j=i+1; j<k; j++){
      if(visit[v[j].first][v[j].second]==0){
        cnt++;
      }
    }
  }
  cout << cnt;
}