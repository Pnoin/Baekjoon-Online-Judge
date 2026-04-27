#include <cstdio>

int main(){
  int x,y;                     //12     3
  scanf("%d%d",&x,&y);
  int sum=x;                  //12
  for(int i=1; i<=y; i++){    //y=1,2,3    3번 작동 
    x=x*10;                  //i=1, x=120         i=2, x=1200           i=3, x= 12000
    sum=sum+x;               
  }  
  printf("%d", sum);
}