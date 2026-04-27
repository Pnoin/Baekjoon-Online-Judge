#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,q,total=0;
  cin >> n >> q;
  int cnt=0;
  for(int i=0; i<=n; i++){
    for(int j=0; j<60; j++){
      for(int k=0; k<60; k++){
        if(k/10==q or k%10==q or j/10==q or j%10==q or i/10==q or i%10==q){
          total++;
        }
      }
    }
  }
  cout << total;
}