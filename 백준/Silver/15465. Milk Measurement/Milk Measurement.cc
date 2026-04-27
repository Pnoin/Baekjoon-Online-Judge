#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int n, cnt=0;
  cin >> n;
  int arr[105][3]={}, mx[105]={};
  for(int i=0; i<101; i++){
    for(int j=0; j<3; j++){
      arr[i][j]=7;
    }
  }
  for(int i=0; i<n; i++){
    int day, cg;
    string name;
    cin >> day >> name >> cg;
    for(int j=day; j<=100; j++){
      if(name=="Bessie"){
        arr[j][0]+=cg;
      }
      else if(name=="Elsie"){
        arr[j][1]+=cg;
      }
      else if(name=="Mildred"){
        arr[j][2]+=cg;
      }
    }
  }
  for(int i=0; i<101; i++){
    for(int j=0; j<3; j++){
      if(arr[i][j]==max(arr[i][0], max(arr[i][1], arr[i][2]))){
        if(j==0){
          mx[i]+=100;
        }
        else if(j==1){
          mx[i]+=10;
        }
        else{
          mx[i]+=1;
        }
      }
    }
  }
  for(int i=0; i<100; i++){
    if(mx[i]!=mx[i+1]){
      cnt++;
    }
  }
  cout << cnt;
}