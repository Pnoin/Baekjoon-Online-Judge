#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string arr[55]={};

int fx(){
  int mx;
  for(int i=0; i<n; i++){
    int cnt=1;
    for(int j=0; j<n-1; j++){
      if(arr[i][j]==arr[i][j+1]){
        cnt++;
      }
      else{
        mx=max(mx,cnt);
        cnt=1;
      }
    }
    mx=max(mx,cnt);
  }
  for(int i=0; i<n; i++){
    int cnt=1;
    for(int j=0; j<n-1; j++){
      if(arr[j][i]==arr[j+1][i]){
        cnt++;
      }
      else{
        mx=max(mx,cnt);
        cnt=1;
      }
    }
    mx=max(mx,cnt);
  }
  return mx;
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  int mx2=0; 
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1; j++){
      swap(arr[i][j],arr[i][j+1]);
      mx2=max(fx(), mx2);
      swap(arr[i][j],arr[i][j+1]);
      swap(arr[j][i],arr[j+1][i]);
      mx2=max(fx(), mx2);
      swap(arr[j][i],arr[j+1][i]);
    }
  }
  cout << mx2;
}