#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int x,a,b,c,money=0,m=0;
  scanf("%d", &x);
  for(int i=0; i<x; i++){
    scanf("%d%d%d", &a,&b,&c);
    if(a!=b and b!=c and c!=a){
      money=max(a,max(b,c)) * 100;
    }
    else if(a==b and b==c){
      money=10000+a*1000;
    }
    else if((a==b and a!=c) or (a==c and a!=b) or (b==c and b!=a)){
      if(a==b and a!=c){
        money=1000+a*100;
      }
      else if(a==c and a!=b){
        money=1000+a*100;
      }
      else if(b==c and b!=a){
        money=1000+b*100;
      }
    }
    if(money>m){
      m=money;
    }
  }
  printf("%d", m);
}