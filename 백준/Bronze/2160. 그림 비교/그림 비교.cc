#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,diff=0,x=0,y=0,mindiff=1000000;
  cin >> n;
  char a[55][55][55]={};
  for(int i=1; i<=n; i++){
    for(int j=0; j<5; j++){
      for(int k=0; k<7; k++){
        cin >> a[i][j][k];
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i>=j){
        continue;
      }
      else{
        diff=0;
        for(int k=0; k<5; k++){
          for(int l=0; l<7; l++){
            if(a[i][k][l]!=a[j][k][l]){
              diff++;
            }
          }
        }
        if(diff<mindiff){
          mindiff=diff;
          x=i;
          y=j;
        }
      }
    }
  }
  cout << x <<' '<< y;
}