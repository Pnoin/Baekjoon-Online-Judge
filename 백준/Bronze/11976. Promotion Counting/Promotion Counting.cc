#include <cstdio>

int main(){
  int a[10]={},b[10]={},totala=0,totalb=0,news=0;
  for(int i=0; i<4; i++){
    scanf("%d%d", &a[i],&b[i]);
    totala=totala+a[i];
    totalb=totalb+b[i];
  }
  news=totalb-totala;
  for(int i=0; i<4; i++){
    if(i<3){
      printf("%d\n", a[i]+news-b[i]);
      news=a[i]+news-b[i];
    }
  }
}