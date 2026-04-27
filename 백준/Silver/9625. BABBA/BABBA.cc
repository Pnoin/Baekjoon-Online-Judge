#include <cstdio>

int main(){
  int n,a[50]={},b[50]={};
  scanf("%d", &n);
  for(int i=0; i<=n; i++){
    if(i==0){
      a[i]=1;
      b[i]=0;
    }
    else if(i==1){
      a[i]=0;
      b[i]=1;
    }
    else{
      a[i]=a[i-2]+b[i-2];
      b[i]=a[i-1]+b[i-1];
    }
  }
  printf("%d %d", a[n],b[n]);
}