#include <cstdio>

int main(){
  int n,m,a[33000];
  scanf("%d", &n);
  for(int i=1; i<n; i++){
    scanf("%d",&m);
    a[m]=1;
  }
  for(int l=1; l<=n; l++){
    if(a[l]==0){
      printf("%d",l);
    }
  }
}