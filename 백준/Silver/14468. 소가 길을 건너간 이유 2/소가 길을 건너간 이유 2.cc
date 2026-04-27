#include <iostream>
#include <string>
using namespace std;

int main(){
  int arr[60]={}, brr[60]={}, total=0;
  char a[55]={};
  for(int i=0; i<52; i++){
    cin >> a[i];
  }
  for(int i=0; i<52; i++){
    for(int j=0; j<52; j++){
      if(a[i]==a[j]){
        if(i<j){
          arr[a[i]-65]=i;
          brr[a[i]-65]=j;
        }
        else if(i>j){
          arr[a[i]-65]=j;
          brr[a[i]-65]=i;
        }
      }
    }
  }
  for(int i=0; i<52; i++){
    for(int j=0; j<52; j++){
      if(arr[j]>arr[i] and brr[j]>brr[i] and brr[i]>arr[j]){
        total++;
      }
    }
  }
  cout << total;
}