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

int n, visit[10][10]={}, mx=-2e9, mn=2e9;
char arr[10][10]={};
int dx[2]={0,1};
int dy[2]={1,0};

void dfs(int y, int x, int cur, int op){
	visit[y][x]=1; 
	if(x==n-1 && y==n-1){
		if(cur<mn){
			mn=cur;
		}
		if(cur>mx){
			mx=cur;
		}
	}
	for(int i=0; i<2; i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<0 || y<0 || x>=n || y>=n){
			continue;
		}
		if(visit[yy][xx]==0){
			int temp=arr[yy][xx]-48;
			if(op==1){
				dfs(yy,xx,cur+temp,0);
			}
			else if(op==2){
				dfs(yy,xx,cur-temp,0);
			}
			else if(op==3){
				dfs(yy,xx,cur*temp,0);
			}
			else{
				if(arr[yy][xx]=='+'){
					dfs(yy,xx,cur,1);
				}
				else if(arr[yy][xx]=='-'){
					dfs(yy,xx,cur,2);
				}
				else if(arr[yy][xx]=='*'){
					dfs(yy,xx,cur,3);
				}
			}
		}
	}
	visit[y][x]=0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	int tp=arr[0][0]-48;
	dfs(0,0,tp,0);
	cout << mx << ' ' << mn;
}