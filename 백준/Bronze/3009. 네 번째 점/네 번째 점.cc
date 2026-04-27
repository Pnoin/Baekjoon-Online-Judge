#include <cstdio>

int main(){
  int a,b,c,d,e,f,g,h;
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  if(a==c){
    g=e;
  }
  else if(a==e){
    g=c;
  }
  else if(c==e){
    g=a;
  }
  if(b==d){
    h=f;
  }
  else if(b==f){
    h=d;
  }
  else if(d==f){
    h=b;
  }
  printf("%d %d", g, h);
}