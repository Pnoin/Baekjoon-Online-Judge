#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n,m,total=0,visit[105][105]={},dis=0;
vector <int> v;
string s;
char arr[105][105]={};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dx2[4]={-1,-1,1,1};
int dy2[4]={1,-1,1,-1};

void dfs(int y, int x, int inx, int dd, int cnt){
  if(inx==s.size()-1){
    total++;
    return;
  }
  visit[y][x]=1; 
  if(cnt==0){
    for(int i=0; i<4; i++){
      int yy=dy[i]+y, xx=dx[i]+x;
      if(yy>=n or xx>=m or xx<0 or yy<0){
        continue;
      }
      if(inx==0){
        dis=i;
      }
      if(visit[yy][xx]==0 and arr[yy][xx]==s[inx+1]){
        int nxtinx=inx+1;
        if(inx==0){
          dfs(yy,xx,nxtinx,dis,0);
        }
        else{
          if(i==dis){
            dfs(yy,xx,nxtinx,i,0);
          }
          else if(i!=dis){
            dfs(yy,xx,nxtinx,i,1);
          }
        }
      }
    }
  }
  else if(cnt==1){
    int yy=dy[dd]+y, xx=dx[dd]+x;
    if(yy>=n or xx>=m or xx<0 or yy<0){
      return;
    }
    if(visit[yy][xx]==0 and arr[yy][xx]==s[inx+1]){
      dfs(yy,xx,inx+1,dd,1);
    }
  }
  visit[y][x]=0;
}

void ddfs(int y, int x, int inx, int dd, int cnt){
  if(inx==s.size()-1){
    total++;
    return;
  }
  visit[y][x]=1; 
  if(cnt==0){
    for(int i=0; i<4; i++){
      int yy=dy2[i]+y, xx=dx2[i]+x;
      if(yy>=n or xx>=m or xx<0 or yy<0){
        continue;
      }
      if(inx==0){
        dis=i;
      }
      if(visit[yy][xx]==0 and arr[yy][xx]==s[inx+1]){
        int nxtinx=inx+1;
        if(inx==0){
          ddfs(yy,xx,nxtinx,dis,0);
        }
        else{
          if(i==dis){
            ddfs(yy,xx,nxtinx,i,0);
          }
          else if(i!=dis){
            ddfs(yy,xx,nxtinx,i,1);
          }
        }
      }
    }
  }
  else if(cnt==1){
    int yy=dy2[dd]+y, xx=dx2[dd]+x;
    if(yy>=n or xx>=m or xx<0 or yy<0){
      return;
    }
    if(visit[yy][xx]==0 and arr[yy][xx]==s[inx+1]){
      ddfs(yy,xx,inx+1,dd,1);
    }
  }
  visit[y][x]=0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin >> s;
	cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j]==s[0]){
        dfs(i,j,0,0,0);
      }
    }
  }
  memset(visit,0,sizeof(visit));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j]==s[0]){
        ddfs(i,j,0,0,0);
      }
    }
  }
  cout << total;
}