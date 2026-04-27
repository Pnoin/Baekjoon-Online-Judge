#include <cstdio>

int main(){
  int a,b,c,d,arr[101]={},num=0;
  scanf("%d%d%d%d", &a,&b,&c,&d);
  for(int i=a; i<b; i++){
    if(arr[i]==0){
      arr[i]=1;
    }
  }
  for(int k=c; k<d; k++){
    if(arr[k]==0){
      arr[k]=1;
    }
  }
  for(int l=0; l<=101; l++){
    if(arr[l]==1){
      num=num+1;
    }
  }
  printf("%d", num);
}