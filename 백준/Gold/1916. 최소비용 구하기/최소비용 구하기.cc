#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n, m, INF=1e9;
vector <pair<int,int>> v[1005];
int arr[1005]={};

void dijkstra(int cur){
  arr[cur]=0;
  priority_queue<pair<int,int>> pq;
  pq.push({cur,0});
  while(!pq.empty()){
    int loc=pq.top().first;
    int dis=-pq.top().second;
    pq.pop();
    if(arr[loc]<dis){
      continue;
    }
    for(int i=0; i<v[loc].size(); i++){
      int nxt=v[loc][i].first;
      int nxtdis=dis+v[loc][i].second;
      if(nxtdis < arr[nxt]){
        arr[nxt]=nxtdis;
        pq.push({nxt,-nxtdis});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    arr[i]=INF;
  }
  cin >> m;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    v[a].push_back({b,c});
  }
  int x,y;
  cin >> x >> y;
  dijkstra(x);
  cout << arr[y];
}
