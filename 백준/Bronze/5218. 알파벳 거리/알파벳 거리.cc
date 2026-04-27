#include <iostream>
#include <string>
using namespace std;

int main(){
  int a, dis=0;
  scanf("%d", &a);
  for(int i=0; i<a; i++){
    string x,y;
    cin >> x >> y;
    cout << "Distances: ";
    for(int j=0; j<x.size(); j++){
      if(x[j]>y[j]){
        printf("%d ", (y[j]+26) - x[j]);
      }
      else if(y[j]>x[j]){
        printf("%d ", y[j]-x[j]);
      }
      else{
        printf("%d ", 0);
      }
    }
    cout << "\n";
  }
}