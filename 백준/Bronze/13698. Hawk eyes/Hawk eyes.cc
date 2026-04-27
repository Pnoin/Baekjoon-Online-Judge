#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
  int arr[4]={1, 0, 0, 2};
  string a;
  cin >> a;
  for(int i=0; i<a.size(); i++){
    if(a[i]=='A'){
      swap(arr[0], arr[1]);
    }
    else if(a[i]=='B'){
      swap(arr[0], arr[2]);
    }
    else if(a[i]=='C'){
      swap(arr[0], arr[3]);
    }
    else if(a[i]=='D'){
      swap(arr[1], arr[2]);
    }
    else if(a[i]=='E'){
      swap(arr[1], arr[3]);
    }
    else if(a[i]=='F'){
      swap(arr[2], arr[3]);
    }
  }
  for(int l=0; l<4; l++){
    if(arr[l]==1){
      printf("%d\n", l+1);
    }
  }
  for(int k=0; k<4; k++){
    if(arr[k]==2){
      printf("%d", k+1);
    }
  }
}