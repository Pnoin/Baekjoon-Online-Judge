#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int n,k,a[1005]={},max=0,total=0;
  scanf("%d%d",&n,&k);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  for(int i=0; i<n; i++){
    total=0;
    for(int j=0; j<n; j++){
      if(a[i]>=a[j] and a[i]-a[j]<=k){
        total++;
      }
    }
    if(total>=max){
      max=total;
    }
  }
  printf("%d", max);
}