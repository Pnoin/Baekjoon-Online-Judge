#include <cstdio>

int main(){
  int a,b,c,arr[105]={},x,y,total=0;
  scanf("%d%d%d", &a,&b,&c);
  for(int i=0; i<3; i++){
    scanf("%d%d",&x,&y);
    for(int j=x; j<y; j++){
      arr[j]++;
    }  
  }
  for(int i=1; i<=100; i++){
    if(arr[i]==1){
      total+=a;
    }
    else if(arr[i]==2){
      total+=b*2;
    }
    else if(arr[i]==3){
      total+=c*3;
    }
  }
  printf("%d", total);
}