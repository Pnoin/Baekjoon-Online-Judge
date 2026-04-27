#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int q, snum=0,llnum=0,total=0;
  string a;
  cin >> q >>a;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='S'){
      snum=snum+1;
    }
    else if(a[i]=='L'){
      llnum=llnum+1;
    }
  }
  total=snum+(llnum/2)+1;
  if(total>q){
    printf("%d", q);
  }
  else{
    printf("%d", total);
  }
}
