#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int arr[300]={};
  string s;      ///baekjoon
  cin >> s;
  for(int i=0; i<300; i++){
    arr[i]=-1;
  }
  for(int i=0; i<s.size(); i++){      
    for(int j=97; j<=122; j++){       
      if(arr[j]==-1){
        if(s[i]==j){                    
          arr[s[i]]=i;                    
        }
      }
    }
  }
  for(int i=97; i<=122; i++){
    printf("%d ",arr[i]);
  }
}