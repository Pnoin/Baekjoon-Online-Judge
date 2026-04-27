#include <iostream>
#include <algorithm>
#include <cstring>
#pragma gcc optimize ("O3")
using namespace std;

int visit[305][305] = {}, n, m, arr[305][305] = {}, cnt = 0, pv[305][305] = {}, q, w;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void afteryear(){
  int pv[305][305] = {};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      pv[i][j] = arr[i][j];
    }
  }
  for(int i=1; i<n-1; i++){
    for(int j=1; j<m-1; j++){
      if(pv[i][j] != 0){
        int cnt = 0;
        for(int k=0; k<4; k++){
          int q=i+dy[k];
          int w=j+dx[k];
          if(pv[q][w] == 0) {
            cnt++;
          }
        }
        arr[i][j] = max(pv[i][j] - cnt, 0);
      }
    }
  }
}

void dfs(int y, int x) {
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (xx <= 0 or yy <= 0 or xx >= m - 1 or yy >= n - 1) {
			continue;
		}
		if (visit[yy][xx] == 0 and arr[yy][xx] != 0) {
			dfs(yy, xx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int total = 0;
	while (true) {
	   memset(visit, 0, sizeof(visit));
	   int cd = 0, cnt = 0;
	   for(int i=1; i<n-1; i++){
	     for(int j=1; j<m-1; j++){
	       if(arr[i][j] != 0 and visit[i][j] == 0) {
	         cnt++;
	         if(cnt == 2) {
	           cd = 1;
	           break;
	         }
	         dfs(i,j);
	       }
	     }
	   }
	   if(cd == 1) {
	     break;
	   }
	   if(cnt == 0) {
	     total = 0;
	     break;
	   }
	   afteryear();
	   total++;
	}
	cout << total;
}	