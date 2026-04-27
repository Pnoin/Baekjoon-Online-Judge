#include <iostream>
#include <string>
using namespace std;

int main(){
  int x=0;
  string a;
  for(int i=1; i<=5; i++){
    cin >> a;
    for(int l=0; l<a.size(); l++){
      if(a[l] == 'F' and a[l+1] == 'B' and a[l+2] == 'I'){
        x=x+1;
        printf("%d ", i);
        break;
      }
    }
  }
  if(x==0){
    printf("HE GOT AWAY!");
  }
}