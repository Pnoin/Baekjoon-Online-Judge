#include <cstdio>

int main(){
  int x,a[105],result=0;
  scanf("%d", &x);
  for(int i=0; i<x; i++){
    scanf("%d", &a[i]);
  }
  for(int l=0; l<x; l++){
    for(int k=0; k<x; k++){
      for(int m=0; m<x; m++){
        if(l==k or k==m or m==l){
          continue;
        }
        if((a[l]-a[k])%a[m]!=0){
          result=result+1;
        } 
      }
    }
  }
  if(result==0){
    printf("yes");
  }
  else{
    printf("no");
  }
}