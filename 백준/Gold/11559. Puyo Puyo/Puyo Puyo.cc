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

int visit[15][10]={}, chain=0;
char arr[15][10]={};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(int y, int x){
  visit[y][x]=1;
  for(int i=0; i<4; i++){
    int yy=y+dy[i];
    int xx=x+dx[i];
    if(yy<0 or xx<0 or yy>=12 or xx>=6){
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
  for(int i=0; i<12; i++){
    for(int j=0; j<6; j++){
      cin >> arr[i][j];
    }
  }
  while(true){
    int temp=0; 
    for(int i=0; i<12; i++){
      for(int j=0; j<6; j++){
        memset(visit,0,sizeof(visit));
        if(arr[i][j]!='.' and visit[i][j]==0){
          dfs(i,j);
        }
        int cnt=0;
        for(int k=0; k<12; k++){
          for(int l=0; l<6; l++){
            if(visit[k][l]==1){
              cnt++;
            }
          }
        }
        if(cnt>=4){
          temp=1;
          for(int k=0; k<12; k++){
            for(int l=0; l<6; l++){
              if(visit[k][l]==1){
                arr[k][l]='.';
              }
            }
          }
        }
      }
    }
    for(int i=0; i<6; i++){ 
      for(int j=10; j>=0; j--){ 
        if(arr[j][i]!='.'){ 
          for(int k=j; k<11; k++){
            if(arr[k+1][i]=='.'){
              arr[k+1][i]=arr[k][i];
              arr[k][i]='.';
            }
            else{
              break;
            }
          } 
        } 
      } 
    }
    if(temp==1){
      chain++;
    }
    else if(temp==0){
      break;
    }
  }
  cout << chain;
}
