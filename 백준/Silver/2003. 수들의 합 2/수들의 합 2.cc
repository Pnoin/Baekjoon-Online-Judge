#include <iostream>
using namespace std;

int main(){
  int n,m,arr[10005]={},b=0,all=0; 
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  for(int i=0; i<n; i++){
    int total=0;
    for(int j=i; j<n; j++){
      total+=arr[j];
      if(total==m){
        all+=1;
        break;
      }
    }
  }
  cout << all;
}