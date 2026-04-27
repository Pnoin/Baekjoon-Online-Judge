#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,m,arr[55][55]={},visit[55][55]={},cnt=0;
int dx[8]={0,0,-1,1,1,-1,-1,1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

void dfs(int y, int x){
    visit[y][x]=1;
    for(int i=0; i<8; i++){
        int yy=y+dy[i];
        int xx=x+dx[i];
        if(x<0 || y<0 || x>=n || y>=m){
            continue;
        }
        if(visit[yy][xx]==0 && arr[yy][xx]==1){
            dfs(yy,xx);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n >> m;
        cnt=0;
        if(n==0 && m==0){
            break;
        }
        memset(arr,0,sizeof(arr));
        memset(visit,0,sizeof(visit));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visit[i][j]==0 && arr[i][j]==1){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}