#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int x,y;
  scanf("%d",&x);
  string a;
  for(int i=0; i<x; i++){
    cin >> y >> a;
    for(int j=0; j<a.size(); j++){
      if(j==y-1){
        continue;
      }
      cout << a[j];
    }
    printf("\n");
  }
}