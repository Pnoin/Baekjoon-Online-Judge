#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int x=1,y=0,z=0;
  string a;
  cin >> a;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='A'){
      swap(x,y);
    }
    else if(a[i]=='B'){
      swap(y,z);
    }
    else if(a[i]=='C'){
      swap(x,z);
    }
  }
  if(x==1){
    printf("%d", 1);
  }
  else if(y==1){
    printf("%d", 2);
  }
  else if(z==1){
    printf("%d", 3);
  }
}