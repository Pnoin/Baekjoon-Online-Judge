#include <cstdio>

int main(){
  int a,b,c,d,num=0,max=0;
  for(int i=1; i<=5; i++){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a+b+c+d>max){
      max=a+b+c+d;
      num=i;
    }
  }
  printf("%d %d", num, max);
}