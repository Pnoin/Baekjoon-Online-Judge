#include <iostream>
using namespace std;

int main(){
  int n, arr[15][15]={}, total=0;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char a;
      cin >> a;
      arr[i][j]=a;
    }
  }
  for(int i=n-1; i>=0; i--){
    for(int j=n-1; j>=0; j--){
      if(arr[i][j]=='1'){
        for(int k=0; k<=i; k++){
          for(int l=0; l<=j; l++){
            if(arr[k][l]=='0'){
              arr[k][l]='1';
            }
            else{
              arr[k][l]='0';
            }
          }
        }
        total++;
      }
    }
  }
  cout << total;
}