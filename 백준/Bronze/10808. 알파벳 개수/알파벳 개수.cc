#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int arr[27]={};
  string a;
  cin >> a;
  for(int i=0; i<a.size(); i++){
    int x=a[i]-97;
    arr[x]=arr[x]+1;
  }
  for(int l=0; l<26; l++){
    printf("%d ", arr[l]);
  }
}