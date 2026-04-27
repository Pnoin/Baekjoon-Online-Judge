#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, q, mn=1000000000;
  pair <int,int> arr[105];
  cin >> n >> q;
  for(int i=0; i<n; i++){
    cin >> arr[i].first >> arr[i].second;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int a=(arr[i].first)+1, b=(arr[j].second)+1, w=0,e=0,r=0,t=0;
      for(int k=0; k<n; k++){
        int x=arr[k].first, y=arr[k].second;
        if(x>a and y>b){
          w++;
        }
        else if(x<a and y>b){
          e++;
        }
        else if(x>a and y<b){
          r++;
        }
        else{
          t++;
        }
      }
      int mx=max(max(max(w,e),r),t);
      mn=min(mn,mx);
    }
  }
  cout << mn;
}