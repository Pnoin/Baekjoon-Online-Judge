#include <iostream>
#include <string>
using namespace std;

int main(){
  int r,c, a[5]={}, count=0;
  cin >> r >> c;
  char arr[55][55]={};
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<r-1; i++){
    for(int j=0; j<c-1; j++){
      count=0;
      if(arr[i][j]=='#' or arr[i+1][j]=='#' or arr[i][j+1]=='#' or arr[i+1][j+1]=='#'){
        continue;
      }
      else{
        if(arr[i][j]=='X'){
          count++;
        }
        if(arr[i+1][j]=='X'){
          count++;
        }
        if(arr[i][j+1]=='X'){
          count++;
        }
        if(arr[i+1][j+1]=='X'){
          count++;
        }
      }
      a[count]++;
    }
  }
  for(int i=0; i<5; i++){
    cout << a[i] << "\n";
  }
}