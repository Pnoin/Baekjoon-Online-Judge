#include <cstdio>

int main(){
  while(true){
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);
    if(a!=0 and b!=0 and c!=0){
      if(a+b>c and b+c>a and c+a>b){
        if(a!=b and b!=c and c!=a){
          printf("Scalene\n");
        }
        else if(a==b or b==c or c==a){
          if(a==b and b==c){
            printf("Equilateral\n");
          }
          else{
            printf("Isosceles\n");
          }
        }
      }
      else if(a+b<=c or b+c<=a or c+a<=b){
        printf("Invalid\n");
      }
    }
    if(a==0 and b==0 and c==0){
      break;
    }
  }
}