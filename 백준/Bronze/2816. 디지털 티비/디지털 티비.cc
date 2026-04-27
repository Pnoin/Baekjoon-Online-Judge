#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,x=0,y=0;
  scanf("%d", &n);
  string a[105]={};
  for(int i=1; i<=n; i++){
    cin >> a[i];
    if(a[i]=="KBS1"){
      x=i;
    }
    if(a[i]=="KBS2"){
      y=i;
    }
  }
  for(int i=1; i<x; i++){
    printf("%d", 1);
  }
  for(int i=1; i<x; i++){
    printf("%d", 4);
  }
  if(x>y){
    y+=1;
  }
  for(int i=1; i<y; i++){
    printf("%d", 1);
  }
  for(int i=1; i<y-1; i++){
    printf("%d", 4);
  }
}