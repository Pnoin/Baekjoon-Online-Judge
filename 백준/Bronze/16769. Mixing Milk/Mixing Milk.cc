#include <cstdio>

int main(){
  int CapA, AmountA, CapB, AmountB, CapC, AmountC;
  scanf("%d%d%d%d%d%d", &CapA, &AmountA, &CapB, &AmountB, &CapC, &AmountC);
  for(int i=0; i<33; i++){
    AmountB=AmountA+AmountB;
    AmountA=0;
    if(AmountB>CapB){
      AmountA=AmountB-CapB;
      AmountB=CapB;
    }
    AmountC=AmountB+AmountC;
    AmountB=0;
    if(AmountC>CapC){
      AmountB=AmountC-CapC;
      AmountC=CapC;
    }
    AmountA=AmountA+AmountC;
    AmountC=0;
    if(AmountA>CapA){
      AmountC=AmountA-CapA;
      AmountA=CapA;
    }
  }
  AmountB=AmountA+AmountB;
  AmountA=0;
  if(AmountB>CapB){
    AmountA=AmountB-CapB;
    AmountB=CapB;
  }
  printf("%d\n%d\n%d",AmountA,AmountB,AmountC);
}