#include <iostream>
#include <algorithm>
using namespace std;

int n,d,k,c,lo=0,hi=-1,mx=0,num[6000005]={},ck[3005]={},total;

int main(){
  cin >> n >> d >> k >> c;
  for(int i=0; i<n; i++){
    cin >> num[i];
    num[i+n]=num[i];
    if(i < k){
      if(ck[num[i]]==0){
        mx++;
      }
      ck[num[i]]++;
      hi++;
    }
  }
  total = mx;
  if(ck[c]==0){
    mx++;
  }
  while(true){
    if(lo+1==n){
      break;
    }
    ck[num[lo]]--;
    if(ck[num[lo]]==0){
      total--;
    }
    lo++;
    hi++;
    if(ck[num[hi]]==0){
      total++;
    }
    ck[num[hi]]++;
    if(ck[c]==0){ 
      int x=total+1;
      mx=max(x,mx);
    }
    else{
      mx=max(total,mx);
    }
  } 
  cout << mx;
}