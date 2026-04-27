#include <cstdio>

int main(){
  int a,arr[105],tot=0;
  scanf("%d", &a);
  for(int i=0; i<a; i++){
    int num=0;
    scanf("%d", &arr[i]);
    if(arr[i]==1){
      continue;
    }
    else if(arr[i]==2){
      tot++;
    }
    else{
      for(int j=2; j<arr[i]; j++){
        if(arr[i]%j==0){
          num++;
        }
      }
      if(num==0){
        tot++;
      }
    }
  }
  printf("%d", tot);
}