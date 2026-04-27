#include <cstdio>

int main(){
  int x, y, a[50], even=0, odd=0;
  scanf("%d", &x);
  for(int i=0; i<x; i++){
    scanf("%d", &y);
    even=0;
    odd=0;
    for(int l=0; l<y; l++){
      scanf("%d", &a[i]);
      if(a[i]%2==0){
        even=even+a[i];
      }
      else{
        odd=odd+a[i];
      }
    }
    if(even>odd){
      printf("EVEN\n");
    }
    else if(odd>even){
      printf("ODD\n");
    }
    else{
      printf("TIE\n");
    }
  }
}