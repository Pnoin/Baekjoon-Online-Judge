#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int k,n,t,g=0,total=0;
  char z;
  cin >> k >> n;
  for(int i=0; i<n; i++){
    cin >> t >> z;
    total+=t;
    if(total>=210){
      break;
    }
    if(z=='T'){
      if(k!=8){
        k++;
      }
      else{
        k=1;
      }
    }
  }
  printf("%d", k);
}