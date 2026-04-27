#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
  int x;
  scanf("%d", &x);
  string y;
  int add=0, score=0;
  for(int i=0; i<x; i++){
    cin >> y;
    int add=0, score=0;
    for(int l=0; l<y.size(); l++){
      if(y[l]=='O'){
        add=add+1;
        score=score+add;
      }
      else if(y[l]=='X'){
        add=0;
      }
    }
    printf("%d\n", score);
  }
}