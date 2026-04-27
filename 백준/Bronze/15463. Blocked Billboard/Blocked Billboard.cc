///1157    2563          15463

#include <cstdio>

int arr[2005][2005]={};
int main(){
  int x,y,a,b,total=0;
  for(int i=0; i<2; i++){
    scanf("%d%d%d%d",&y,&x,&b,&a);
    y+=1000;
    x+=1000;
    b+=1000;
    a+=1000;
    for(int j=x; j<a; j++){
      for(int k=y; k<b; k++){
        arr[j][k]=1;
      }
    }
  }
  scanf("%d%d%d%d",&y,&x,&b,&a);
  y+=1000;
  x+=1000;
  b+=1000;
  a+=1000;
  for(int i=x; i<a; i++){
    for(int j=y; j<b; j++){
      arr[i][j]=0; 
    }
  }
  for(int i=0; i<2000; i++){
    for(int j=0; j<2000; j++){
      if(arr[i][j]==1){
        total++;
      }
    }
  }
  printf("%d", total);
}