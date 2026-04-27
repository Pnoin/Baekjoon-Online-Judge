#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int total=0;
  char a;
  for(int i=1; i<=8; i++){
    for(int j=1; j<=8; j++){
      cin >> a;
      if(i%2==0 and j%2==0){
        if(a=='F'){
          total=total+1;
        }
      }
      else if(i%2==1 and j%2==1){
        if(a=='F'){
          total=total+1;
        }
      }
    }
  }
  printf("%d", total);
}