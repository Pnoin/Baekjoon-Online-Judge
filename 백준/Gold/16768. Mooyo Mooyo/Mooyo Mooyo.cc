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

int visit[105][15]={};
char arr[105][15]={};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n,q;

void dfs(int y, int x){
  visit[y][x]=1;
  for(int i=0; i<4; i++){
    int yy=y+dy[i];
    int xx=x+dx[i];
    if(yy<0 or xx<0 or yy>=n or xx>=10){
      continue; 
    }
    if(visit[yy][xx]==0 and arr[yy][xx]==arr[y][x]){
      dfs(yy,xx);
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++){
      cin >> arr[i][j];
    }
  }
  while(true){
    int temp=0; 
    for(int i=0; i<n; i++){
      for(int j=0; j<10; j++){
        memset(visit,0,sizeof(visit));
        if(arr[i][j]!='0' and visit[i][j]==0){
          dfs(i,j);
        }
        int cnt=0;
        for(int k=0; k<n; k++){
          for(int l=0; l<10; l++){
            if(visit[k][l]==1){
              cnt++;
            }
          }
        }
        if(cnt>=q){
          temp=1;
          for(int k=0; k<n; k++){
            for(int l=0; l<10; l++){
              if(visit[k][l]==1){
                arr[k][l]='0';
              }
            }
          }
        }
      }
    }
    for(int i=0; i<10; i++){ 
      for(int j=n-1; j>=0; j--){ 
        if(arr[j][i]!='0'){ 
          for(int k=j; k<n-1; k++){
            if(arr[k+1][i]=='0'){
              arr[k+1][i]=arr[k][i];
              arr[k][i]='0';
            }
            else{
              break;
            }
          } 
        } 
      } 
    }
    if(temp==0){
      break;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++){
      cout << arr[i][j];
    }
    cout << '\n';
  }
}
