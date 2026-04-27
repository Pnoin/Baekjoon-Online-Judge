#include <iostream>
#include <string>
using namespace std;

int main(){
  int r,c,zr,zc;
  cin >> r >> c >> zr >> zc;
  char arr[55][55]={};
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<r; i++){          
    for(int l=0; l<zr; l++){                                    ///3
      for(int j=0; j<c; j++){                        ///3                   ///1
        for(int k=0; k<zc; k++){                   ///2
          cout << arr[i][j];                       
        }
      }
      cout << "\n";
    }
  }
}