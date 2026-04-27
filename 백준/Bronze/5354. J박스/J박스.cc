#include <cstdio>

int main(){
  int x,y;
  scanf("%d",&x);
  for(int i=0; i<x; i++){
    scanf("%d", &y);
    for(int l=1; l<=y; l++){               //
      for(int h=1; h<=y; h++){
        if(l==1 or l==y or h==1 or h==y){
          printf("#");
        }
        else{
          printf("J");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}