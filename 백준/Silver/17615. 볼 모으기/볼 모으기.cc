#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n, redleft=0, redright=0, blueleft=0, blueright=0, cnt=0;
  string a;
  cin >> n >> a;
  for(int i=0; i<n; i++){
    if(a[i]=='B'){
      cnt=1; 
    }
    else if(a[i]=='R' and cnt==1){
      redleft++;
    }
  }
  cnt=0; 
  for(int i=0; i<n; i++){
    if(a[i]=='R'){
      cnt=1; 
    }
    else if(a[i]=='B' and cnt==1){
      blueleft++;
    }
  }
  cnt=0; 
  for(int i=n-1; i>=0; i--){
    if(a[i]=='B'){
      cnt=1; 
    }
    else if(a[i]=='R' and cnt==1){
      blueright++;
    }
  }
  cnt=0; 
  for(int i=n-1; i>=0; i--){
    if(a[i]=='R'){
      cnt=1; 
    }
    else if(a[i]=='B' and cnt==1){
      redright++;
    }
  }
  cnt=0; 
  cout << min(min(min(redleft, redright), blueleft), blueright);
}