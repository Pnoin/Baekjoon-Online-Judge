#include <cstdio>

int main(){
  int a[10],total=0,x=0,y=0;
  for(int i=0; i<9; i++){
    scanf("%d", &a[i]);
    total=total+a[i];
  }
  for(int l=0; l<9; l++){
    for(int m=0; m<9; m++){
      if(a[l]==a[m]){
        continue;
      }
      if(total-a[l]-a[m]==100){
        x=l;
        y=m;
      }
    }
  }
  for(int j=0; j<9; j++){
    if(j==x or j==y){
      continue;
    }
    printf("%d\n", a[j]);
  }
}