#include <cstdio>

int main(){
  int x,y,d[12]={0,31,28,31,30,31,30,31,31,30,31,30};
  scanf("%d%d",&x,&y);
  for(int i=0; i<x; i++){
    y+=d[i];
  }
  if(y%7==1){
    printf("MON");
  }
  else if(y%7==2){
    printf("TUE");
  }
  else if(y%7==3){
    printf("WED");
  }
  else if(y%7==4){
    printf("THU");
  }
  else if(y%7==5){
    printf("FRI");
  }
  else if(y%7==6){
    printf("SAT");
  }
  else{
    printf("SUN");
  }
}