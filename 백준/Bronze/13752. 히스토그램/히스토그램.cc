#include <cstdio>

int main(){
  int x,y;
  scanf("%d", &x);
  for(int i=0; i<x; i++){
    scanf("%d", &y);
    for(int j=0; j<y; j++){
      printf("=");
    }
    printf("\n");
  }
}