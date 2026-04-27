#include <cstdio>

int main(){
  int N,W,H,M;
  scanf("%d%d%d", &N, &W, &H);
  for(int i=1; i<=N; i++){
    scanf("%d",&M);
    if(M<=W or M<=H or M*M<=(H*H)+(W*W)){
      printf("DA\n");
    }
    else{
      printf("NE\n");
    }
  }
}