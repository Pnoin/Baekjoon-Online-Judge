#include <iostream>
#include <string>
using namespace std;

int main(){
  int arr[125]={},max=0,check=0;
  string a;
  cin >> a;
  for(int i=0; i<a.size(); i++){
    if(a[i]>=97 and a[i]<=122){
      arr[a[i]-32]++;      
    }
    else{
      arr[a[i]]++;
    }
  }
  for(int i=65; i<=90; i++){
    if(arr[i]>max){
      max=arr[i];
    }    
  }
  for(int i=65; i<=90; i++){
    if(arr[i]==max){
      check++;
    }
  }
  if(check!=1){
    printf("?");
  }
  else{
    for(int i=65; i<=90; i++){
      if(arr[i]==max){
        printf("%c", i);
      }
    }
  }
}
