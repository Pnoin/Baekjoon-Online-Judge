#include <cstdio>

int main(){
  int n,a[100000], min=1000000000, x=0;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);                
    if(a[i]<min){                       
      min=a[i];                        
      x=i;                              
    }
  }
  printf("%d", x);
}