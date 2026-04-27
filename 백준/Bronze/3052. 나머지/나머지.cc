#include <cstdio>

int main(){
  int x,y,z=0,a[1000]={};
  for(int i=0; i<10; i++){
    scanf("%d", &x);
    y=x%42;
    if(a[y]==0){
      z=z+1;
    }
    else{
      continue;
    }
    a[y]=1;
  }
  printf("%d",z);
}