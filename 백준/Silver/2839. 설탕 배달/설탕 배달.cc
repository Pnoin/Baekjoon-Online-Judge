#include <cstdio>
int main(){
  int x,y=0,z=5000;
  scanf("%d", &x);
  for(int i=0; i<5000; i++){
    for(int j=0; j<5000; j++){
      if(5*i+3*j==x){
        y=i+j;
        if(y<z){
          z=y;
        }
      }
    }
  }
  if(z==5000){
    printf("%d", -1);
  }
  else{
    printf("%d", z);
  }
}