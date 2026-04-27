#include <cstdio>

int main(){
  int x,y,a[105]={0},sum=0;
  scanf("%d", &x);
  for(int i=0; i<x; i++){
    scanf("%d", &y);
    if(a[y]==0){
      a[y]=1;
    }
    else if(a[y]==1){
      sum=sum+1;
    }
  }
  printf("%d", sum);
}