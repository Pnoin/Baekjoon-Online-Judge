#include <cstdio>

int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  int x=a/100, y=a/10%10, z=a%10;
  int c= 100*z + 10*y + x;
  int X=b/100, Y=b/10%10, Z=b%10;
  int d= 100*Z + 10*Y + X;
  if(c>d){
    printf("%d", c);
  }
  else if(d>c){
    printf("%d", d);
  }
}

