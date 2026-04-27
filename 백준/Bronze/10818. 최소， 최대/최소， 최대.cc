#include <cstdio>

int main(){
  int a, b, min=1000000, max=-1000000;
  scanf("%d", &a);
  for(int i=1; i<=a; i++){
    scanf("%d", &b);
    if(b>max){
      max=b;
    }
    if(b<min){
      min=b;
    }
  }
  printf("%d %d", min, max);
}