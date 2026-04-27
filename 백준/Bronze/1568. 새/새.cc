#include <cstdio>

int main(){
  int a,sec=0, i=1;
  scanf("%d", &a);
  while(true){
    a=a-i;
    i=i+1;
    sec=sec+1;
    if(a<i){
      i=1;
    }
    if(a==0){
      break;
    }
  }
  printf("%d", sec);
}