/// 14467

#include <cstdio>

int main(){
  int n,a,b,arr[11]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},total=0;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d%d",&a,&b);
    if(arr[a]==-1){
      arr[a]=b;
    }
    else if(arr[a]!=b and arr[a]!=-1){
      arr[a]=b;
      total++;
    }
  }
  printf("%d", total);
}