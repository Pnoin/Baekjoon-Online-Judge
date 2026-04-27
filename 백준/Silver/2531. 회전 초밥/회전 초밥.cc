#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[60005]={}, num[3005]={};

int main(){
  int n,d,k,c,mx=0,cnt=0, check=1;
  cin >> n >> d >> k >> c;
  for(int i=0; i<n; i++){
    cin >> arr[i];
    arr[i+n]=arr[i];
  }
  for(int i=0; i<n; i++){
    cnt=0;
    check=1;
    
    for(int j=i; j<i+k; j++){
      if(num[arr[j]]==0){
        num[arr[j]]=1;
      }
      else if(num[arr[j]]==1){
        cnt++;
      }
      if(arr[j]==c){
        check=0; 
      }
    }
    mx=max(mx,check+k-cnt);
    for(int j=0; j<=3000; j++){
      num[j]=0;
    }
  }
  cout << mx; 
}