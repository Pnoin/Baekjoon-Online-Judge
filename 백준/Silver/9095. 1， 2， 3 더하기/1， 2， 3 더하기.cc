///9095

#include <cstdio>

int main(){
  int num=0,arr[20]={};
  while(num<11){
    num=num+1;
    if(num==1){
      arr[num]=1;
    }
    else if(num==2){
      arr[num]=2;
    }
    else if(num==3){
      arr[num]=4;
    }
    else{
      arr[num]=arr[num-1]+arr[num-2]+arr[num-3];
    }
  }
  int t,n;
  scanf("%d", &t);
  for(int i=0; i<t; i++){
    scanf("%d", &n);
    printf("%d\n", arr[n]);
  }
}
