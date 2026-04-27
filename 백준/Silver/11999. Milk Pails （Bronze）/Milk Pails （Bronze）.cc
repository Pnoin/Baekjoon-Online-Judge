#include <cstdio>

int main(){
  int x,y,m,max=0;
  scanf("%d%d%d", &x,&y,&m);
  for(int i=0; i<1000; i++){
    for(int l=0; l<1000; l++){
      if(x*i+y*l<=m and x*i+y*l>=max){
        max=x*i+y*l;
      }
    }
  }
  printf("%d", max);
}