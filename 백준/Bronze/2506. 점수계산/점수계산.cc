#include <cstdio>

int main(){
  int a,b,combo=0,total=0;
  scanf("%d",&a);
  for(int i=0; i<a; i++){
    scanf("%d", &b);
    if(b==1){
      combo=combo+1;
      total=total+combo;
    }
    else if(b==0){
      combo=0;
    }
  }
  printf("%d", total);
}