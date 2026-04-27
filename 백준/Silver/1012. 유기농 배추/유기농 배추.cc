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

int t,n,m,k,visit[55][55]={},arr[55][55]={},cnt=0;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

void dfs(int y, int x){
    visit[y][x]=1;
    for(int i=0; i<4; i++){
        int yy=y+dy[i];
        int xx=x+dx[i];
        if(yy<0 || x<0 || y>=n || x>=m){
            continue;
        }
        if(visit[yy][xx]==0 && arr[yy][xx]==1){
            dfs(yy,xx);
        }
    }
}

void resetall(){
    for(int i=0; i<55; i++){
        for(int j=0; j<55; j++){
            arr[i][j]=0;
            visit[i][j]=0;
        }
    }
    cnt=0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int testcase=0; testcase<t; testcase++){
        resetall();
        cin >> m >> n >> k;
        for(int i=0; i<k; i++){
            int x,y;
            cin >> x >> y;
            arr[y][x]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1 && visit[i][j]==0){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}