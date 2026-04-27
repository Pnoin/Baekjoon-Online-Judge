#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,m,count=0,total=0;
  cin >> n >> m;
  char a[105][105]={}, b[105][105]={};
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> a[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> b[i][j];
    }
  }
  for(int i=0; i<m; i++){
    count=0;
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        if(a[j][i]==b[k][i]){
          count++;
        }
      }
    }
    if(count==0){
      total++;
    }
  }
  cout << total;
}