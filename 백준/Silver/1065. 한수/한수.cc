#include <cstdio>

int main(){
  int n,total=0;
  scanf("%d",&n);
  for(int i=1; i<=n; i++){
    if(i<100){
      total++;
    }
    else{
      if(i/100-(i%100)/10==(i%100)/10-i%10){
        total++;
      }
    }
  }
  printf("%d",total);
}