#include <iostream>
#include <string>
using namespace std;

int main(){
  string a;
  cin >> a;
  for(int i=0; i<a.size(); i++){
    if('A' <= a[i] and 'Z' >= a[i]){
      printf("%c", a[i]);
    }
  }
}
