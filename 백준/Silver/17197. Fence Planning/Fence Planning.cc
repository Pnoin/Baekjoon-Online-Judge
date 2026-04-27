#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> PII;

int n,m, visit[100005], mn=1e9;
vector <int> v[100005];
vector <PII> cor;
vector <int> xcor;
vector <int> ycor;

void dfs(int cur) {
  visit[cur] = 1;
  ycor.push_back(cor[cur].first);
  xcor.push_back(cor[cur].second);
  for (int i=0; i<v[cur].size(); i++) {
    int nxt = v[cur][i];
    if (visit[nxt] == 0) {
      dfs(nxt);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  cor.push_back(make_pair(0,0));
  for(int i=1; i<=n; i++){
    int a,b;
    cin >> a >> b;
    cor.push_back(make_pair(a,b));
  }
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    if(visit[i]==1){
      continue;
    }
    ycor.clear();
    xcor.clear();
    dfs(i);
    sort(ycor.begin(),ycor.end());
    sort(xcor.begin(),xcor.end());
    int xs=xcor[xcor.size()-1]-xcor[0];
    int ys=ycor[ycor.size()-1]-ycor[0];
    mn=min(mn, 2*(xs+ys));
  }
  cout << mn;
}