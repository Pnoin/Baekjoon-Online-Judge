#include <cstdio>

int main(){
  int a,b,c,students,room=0;
  scanf("%d%d%d%d",&a,&b,&c,&students);
  for(int i=0; i<=students; i++){
    for(int j=0; j<=students; j++){
      for(int l=0; l<=students; l++){
        if(students==a*i+b*j+c*l){
          room=room+1;
        }
      }
    }
  }
  if(room==0){
    printf("%d", 0);
  }
  else{
    printf("%d", 1);
  }
}