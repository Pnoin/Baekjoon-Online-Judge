#include <cstdio>

int main(){
  int x,total=0;
  scanf("%d", &x);
  while(x>0){
    if(x%2==1){
      total++;
    }
    x=x/2;
  }
  printf("%d", total);
}
