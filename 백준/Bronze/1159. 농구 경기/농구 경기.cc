#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int x,b[200]={}, w=0;
  scanf("%d", &x);
  string a;
  for(int i=0; i<x; i++){
    cin >> a;
    int q=a[0];
    b[q]=b[q]+1;
  }
  for(int p=97; p<=122; p++){
    if(b[p]>=5){
      printf("%c",p);
      w=w+1;
    }
  }
  if(w==0){
    printf("PREDAJA");
  }
}