#include <iostream>
#include <string>
using namespace std;

int main(){
  string a;
  string b="CAMBRIDGE";
  cin >> a;
  for(int i=0; i<a.size(); i++){
    int count=0;
    for(int l=0; l<9; l++){
      if(a[i]!=b[l]){
        count=count+1;
        if(count==9){
          printf("%c", a[i]);
        }
      }
    }
  }
}