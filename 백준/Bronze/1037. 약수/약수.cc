#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int a,b[50],num=0;
  scanf("%d", &a);
  for(int i=0; i<a; i++){
    scanf("%d", &b[i]);
  }
  sort(&b[0], &b[a]);
  for(int l=0; l<a; l++){
    if(a==1){
      printf("%d", b[l]*b[l]);
    }
    else{
      if(l==a-1){
        printf("%d", b[0]*b[l]);
      }
    }
  }
}