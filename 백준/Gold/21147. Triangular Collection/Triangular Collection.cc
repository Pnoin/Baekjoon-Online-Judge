#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int m, arr[55]={},temp=0;
  long long total=0;
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> arr[i];
  }
  sort(&arr[0], &arr[m]);
  for(int n=0; n<m-2; n++){
    for(int k=n+2; k<m; k++){
      temp=0;
      for(int i=n+1; i<k; i++){
        if(arr[n]+arr[i]>arr[k]){
          temp++;
        }
      }
      total+=pow(2,temp)-1;
    }
  }
  cout << total;
}