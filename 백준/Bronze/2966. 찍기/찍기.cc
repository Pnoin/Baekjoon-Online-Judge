#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
  int n,AdrianTotal=0,BrunoTotal=0,GoranTotal=0,max=0;
  scanf("%d", &n);
  char a[105]={},Arule[3]={'A','B','C'},Brule[4]={'B','A','B','C'},Grule[6]={'C','C','A','A','B','B'};
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i]==Arule[i%3]){  ///0 0     1 1     2 2     3 0     4 1    5 2    6 0
      AdrianTotal++;
    }
    if(a[i]==Brule[i%4]){
      BrunoTotal++;
    }
    if(a[i]==Grule[i%6]){
      GoranTotal++;
    }
  }
  if(AdrianTotal>=max){
    max=AdrianTotal;
  }
  if(BrunoTotal>=max){
    max=BrunoTotal;
  }
  if(GoranTotal>=max){
    max=GoranTotal;
  }
  printf("%d\n", max);
  if(AdrianTotal==max){
    cout << "Adrian" << "\n"; 
  }
  if(BrunoTotal==max){
    cout << "Bruno" << "\n"; 
  }
  if(GoranTotal==max){
    cout << "Goran" << "\n"; 
  }
}