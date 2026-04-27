#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int n, x[55]={}, y[55]={}, count=0;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &x[i], &y[i]);
  }
  for(int i=0; i<n; i++){
    count=0;
    for(int j=0; j<n; j++){
      if(x[i]<x[j] and y[i]<y[j]){
        count++;
      }
    }
    printf("%d ", count+1);
  }
}