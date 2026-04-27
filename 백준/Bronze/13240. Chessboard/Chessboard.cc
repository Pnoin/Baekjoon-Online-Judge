#include <cstdio>

int main(){
  int n,m;
  scanf("%d%d", &n,&m);
  for(int i=1; i<=n; i++){
    for(int l=1; l<=m; l++){
      if(i%2==0 and l%2==0){
        printf("*");
      }
      else if(i%2==1 and l%2==1){
        printf("*");
      }
      else{
        printf(".");
      }
    }
    printf("\n");
  }
}