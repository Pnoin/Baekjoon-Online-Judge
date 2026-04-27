#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k,total=0,arr[100005]={};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(&arr[0],&arr[n]);
  cin >> k;
  int lo=0, hi=n-1;
  while(true){
    if(lo>=hi){
      break;
    }
    if(arr[lo]+arr[hi]==k){
      total++;
      lo++;
      hi--;
    }
    else if(arr[lo]+arr[hi]<k){
      lo++;
    }
    else{
      hi--;
    }
  }
  cout << total;
}