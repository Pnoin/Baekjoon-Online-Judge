#include <cstdio>

int main(){
  int x,y;
  scanf("%d%d", &x,&y);
  for(int i=1; i<=x; i++){
    for(int j=1; j<=y; j++){
      if(x%i==0 and y%j==0){
        printf("%d %d\n", i,j);
      }
    }
  }
}