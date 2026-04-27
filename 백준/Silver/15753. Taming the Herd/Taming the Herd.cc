#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, a[105]={}, q=-1,min=0,max=0; 
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  if(a[0]>0){
    cout << -1;
    return 0;
  }
  a[0]=0;
  for(int i=n-1; i>=0; i--){
    if(q!=-1 and a[i]!=-1 and a[i]!=q){
      cout << -1;
      return 0;
    }
    if(q==-1){
      q=a[i];
    }
    if(a[i]==-1){
      a[i]=q;
    }
    if(a[i]==0){
      min++;
    }
    if(a[i]==-1){
      max++;
    }
    if(q>-1){
      q--;
    }
  }
  cout << min << ' ' << min+max;
}