#include <cstdio>

int main(){
  int n,a[1000],sum=0,combo=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++){ 
    scanf("%d",&a[i]);
    if(a[i]==0){
      if(combo==0){
        combo=combo+1;
        sum=sum+1;
      }
    }
    else if(a[i]==1){
      if(combo==1){
        combo=combo+1;
        sum=sum+1;
      }
    }
    else if(a[i]==2){
      if(combo==2){
        combo=combo+1;
        sum=sum+1;
        combo=0;
      }
    }
  }
  printf("%d", sum);
}