#include <cstdio>

int main(){
  int a[10], b[10], c=0, atotal=0, btotal=0;
  for(int i=0; i<10; i++){
    scanf("%d", &a[i]);
  }
  for(int l=0; l<10; l++){
    scanf("%d", &b[l]);
  }
  for(int k=0; k<10; k++){
    if(a[k]>b[k]){
      atotal=atotal+3;
      c=1;
    }
    else if(b[k]>a[k]){
      btotal=btotal+3;
      c=2;
    }
    else{
      atotal=atotal+1;
      btotal=btotal+1;
    }
  }
  printf("%d %d\n",atotal,btotal);
  
  if(atotal>btotal){
    printf("A");
  }
  else if(btotal>atotal){
    printf("B");
  }
  else{
    if(c==1){
      printf("A");
    }
    else if(c==2){
      printf("B");
    }
    else{
      printf("D");
    }
  }
}