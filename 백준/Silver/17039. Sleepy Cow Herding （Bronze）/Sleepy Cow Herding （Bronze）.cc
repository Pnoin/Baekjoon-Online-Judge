#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int arr[5]={}, min, max=0;
  for(int i=0; i<3; i++){
    cin >> arr[i];
  }
  sort(&arr[0], &arr[3]);
  if(arr[2]-arr[0]==2){
    min=0;
  }
  else if(arr[2]-arr[1]==2 or arr[1]-arr[0]==2){
    min=1;
  }
  else{
    min=2;
  }
  if(arr[2]-arr[1]>max){
    max=arr[2]-arr[1]-1;
  }
  if(arr[1]-arr[0]>max){
    max=arr[1]-arr[0]-1;
  }
  cout << min << "\n" << max;
}