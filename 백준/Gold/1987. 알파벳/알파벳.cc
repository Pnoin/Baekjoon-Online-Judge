#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n, m, visit[95]={}, mx=0;
char arr[25][25]={};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int y, int x, int cnt){
    visit[arr[y][x]]=1;
    if(cnt>mx){
        mx=cnt;
    }
    for(int i=0; i<4; i++){
        int yy=y+dy[i];
        int xx=x+dx[i];
        if(yy<0 || xx<0 || yy>=n || xx>=m){
            continue;
        }
        if(visit[arr[yy][xx]]==0){
            dfs(yy,xx,cnt+1);
            visit[arr[yy][xx]]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    dfs(0,0,1);
    cout << mx;
}