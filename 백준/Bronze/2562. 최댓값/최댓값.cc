#include <cstdio>

int main(){
  int a,b=0,c=0;
  for(int i=1; i<=9; i++){
    scanf("%d", &a);
    if(a>b){
      b=a;
      c=i;
    }
  }
  printf("%d\n%d", b,c);
}