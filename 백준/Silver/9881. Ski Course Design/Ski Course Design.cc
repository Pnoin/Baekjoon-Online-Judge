#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, a[1005]={},total=0, min=99999999; 
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(&a[0],&a[n]);
  for(int i=0; i<=83; i++){
    total=0;
    for(int j=0; j<n; j++){
      if(a[j]<i){
        total+=(i-a[j])*(i-a[j]);
      }
      else if(a[j]>i+17){
        total+=(a[j]-i-17)*(a[j]-i-17);
      }
    }
    if(total<min){
      min=total;
    }
  }
  cout << min;
}