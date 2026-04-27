#include <iostream>
#include <string>
using namespace std;

int main(){
  int a;
  scanf("%d", &a);
  string b;
  for(int i=0; i<a; i++){
    cin >> b;
    for(int l=0; l<b.size(); l++){
      if(b[l]>=65 and b[l]<=90){
        b[l]=b[l]+32;
      }
    }
    cout << b << "\n";
  }
}
