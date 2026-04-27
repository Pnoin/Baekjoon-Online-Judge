#include <cstdio>

int main(){
  int x, a[35]={};
  for(int i=0; i<28; i++){
    scanf("%d", &x);   
    a[x]=1;            
  }
  for(int l=1; l<=30; l++){
    if(a[l]==0){
      printf("%d\n",l);
    }
  }
}