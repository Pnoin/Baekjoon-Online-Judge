#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int x,y;
  scanf("%d",&x);
  string a;
  for(int i=0; i<x; i++){
    scanf("%d", &y);
    cin >> a;
    for(int j=0; j<a.size(); j++){                  
      for(int l=0; l<y; l++){        
        printf("%c", a[j]);
      }
    }
    printf("\n");
  }
}