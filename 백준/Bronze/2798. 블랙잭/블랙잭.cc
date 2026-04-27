#include <cstdio>

int main(){
  int x,y,a[105],max=0;
  scanf("%d%d", &x, &y);
  for(int i=0; i<x; i++){
    scanf("%d", &a[i]);
  }
  for(int l=0; l<x; l++){
    for(int h=0; h<x; h++){
      for(int m=0; m<x; m++){
        if(l==h or h==m or m==l){
          continue;
        } 
        if(a[l]+a[h]+a[m]<=y and a[l]+a[h]+a[m]>max){
          max=a[l]+a[h]+a[m];
        }
      }
    }
  }
  printf("%d", max);
}