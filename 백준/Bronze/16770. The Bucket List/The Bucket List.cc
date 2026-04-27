///16770

#include <cstdio>

int main(){
  int n,s,t,b,arr[1005]={},max=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d%d%d",&s,&t,&b);
    for(int j=s; j<=t; j++){
      arr[j]+=b;
    }
  }
  for(int i=1; i<1001; i++){
    if(arr[i]>max){
      max=arr[i];
    }
  }
  printf("%d", max);
}