#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,clap=0;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    string a = to_string(i);
    for(int l=0; l<a.size(); l++){
      if(a[l]=='3'){
        clap=clap+1;
      }
      else if(a[l]=='6'){
        clap=clap+1;
      }
      else if(a[l]=='9'){
        clap=clap+1;
      }
    }
  }
  printf("%d", clap);
}