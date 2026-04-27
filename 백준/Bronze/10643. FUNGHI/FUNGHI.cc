#include <cstdio>

int main(){
  int a[20]={},max=0;
  for(int i=0; i<16; i++){
    if(i<8){
      scanf("%d", &a[i]);
      a[i+8]=a[i];
    }
  }
  for(int i=3; i<16; i++){
    if(a[i-3]+a[i-2]+a[i-1]+a[i]>=max){
      max=a[i-3]+a[i-2]+a[i-1]+a[i];
    }
  }
  printf("%d",max);
}