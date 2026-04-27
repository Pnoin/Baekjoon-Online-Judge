#include <cstdio>

int main(){
  int a,s,d,min=1000000,max=-1000000;
  scanf("%d", &a);
  for(int i=0; i<a; i++){
    scanf("%d", &s);         
    for(int j=0; j<s; j++){
      scanf("%d", &d);       
      if(d>=max){
        max=d;                     
      }
      if(d<=min){       
        min=d;
      }
    }
    printf("%d %d\n", min,max);
    min=1000000;
    max=-1000000;
  }
}