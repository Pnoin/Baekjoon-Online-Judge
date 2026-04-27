#include <iostream>
using namespace std;

int gcd(int x, int y){
  while(true){
    int z=x;
    x=y;
    y=z%y;
    if(y==0){
      break;
    }
  }
  return x;
}

int main(){
  int p,q,s;
  cin >> p >> q >> s;
  int lcm=p*q/gcd(p,q);
  if(lcm>s){
    cout << "no";
  }
  else{
    cout << "yes";
  }
}