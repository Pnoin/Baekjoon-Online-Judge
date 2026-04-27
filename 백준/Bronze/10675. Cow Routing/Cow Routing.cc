#include <cstdio>

int main(){
  int a,b,n,min=10000;
  scanf("%d%d%d",&a,&b,&n);
  for(int i=0; i<n; i++){
    int cost, num, arr[505]={},ax=-1,bx=-1;
    scanf("%d%d",&cost,&num);
    for(int j=0; j<num; j++){
      scanf("%d",&arr[j]);
    }
    for(int j=0; j<num; j++){
      if(arr[j]==a){
        ax=j;
      }
      else if(arr[j]==b){
        bx=j;
      }
    }
    if(ax<bx and ax!=-1){
      if(cost<min){
        min=cost;
      }
    }
  }
  if(min==10000){
    printf("-1");
  }
  else{
    printf("%d", min);
  }
}