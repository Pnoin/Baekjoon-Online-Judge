#include <cstdio>

int main(){
  int n, a[105]={}, b[105]={},at=0;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &b[i]);
  }
  for(int i=1; i<=n; i++){
    if(i==1){
      a[i]=b[i];
      at=at+a[i];
      printf("%d ",a[i]);
    }
    else{
      a[i]=b[i]*i-at;
      at=at+a[i];
      printf("%d ",a[i]);
    }
  }
}