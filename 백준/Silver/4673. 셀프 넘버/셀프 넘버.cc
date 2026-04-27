#include <iostream>
#include <string>
using namespace std;

int arr[10005]={};

int check(int n){
  int sum=n;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

int main(){
  for(int i=1; i<=10000; i++){
    if(check(i)>10000){
      continue;
    }
    else{
      arr[check(i)]=1;
    }
  }
  for(int i=1; i<=10000; i++){
    if(arr[i]==0){
      cout << i << "\n";
    }
  }
}