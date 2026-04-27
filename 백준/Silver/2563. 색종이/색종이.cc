#include <cstdio>

int main(){
  int n,x,y,arr[105][105]={},total=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d%d", &x,&y);
    for(int j=x; j<x+10; j++){
      for(int k=y; k<y+10; k++){
        if(arr[j][k]==1){
          continue;
        }
        else{
          arr[j][k]++;
        }
      }
    }
  }
  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
      if(arr[i][j]==1){
        total++;
      }
    }
  }
  printf("%d", total);
}