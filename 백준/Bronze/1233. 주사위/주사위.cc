#include <cstdio>

int main(){
  int x,y,z,a[16005],big=0, c=0;
  scanf("%d%d%d", &x,&y, &z);
  for(int i=1; i<=x; i++){
    for(int j=1; j<=y; j++){
      for(int k=1; k<=z; k++){
        a[i+j+k]=a[i+j+k]+1;          
        if(a[i+j+k]>big){
          big=a[i+j+k];
          c=i+j+k;
        }
      }                                  
    }
  }
  printf("%d", c);
}