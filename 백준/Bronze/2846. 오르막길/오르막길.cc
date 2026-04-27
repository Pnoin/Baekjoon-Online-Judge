#include <iostream>
using namespace std;

int main(){
  int n, arr[1005]={}, max=0, check[1005]={}, minus=0;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  int count=0;
  for(int i=0; i<n; i++){        /// 1 2 1 4  (6)
    if(arr[i]<arr[i+1]){           /// 1<2                          2>1
      check[count]=arr[i];         /// count=0, check ={1}
      count++;                    ///count =1
    }
    else if(arr[i]>=arr[i+1]){
      check[count]=arr[i];
      minus=check[count]-check[0];     
      if(minus>max){
        max=minus;
      }
      count=0; 
      minus=0;
    }
  }
  cout << max;
}