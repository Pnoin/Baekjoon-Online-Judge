#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for(int q=0; q<t; q++){
    int n,k;
    char arr[100005]={};
    cin >> n >> k;
    string s;
    cin >> s;
    int curg=-100000, curh=-100000, total=0;
    for(int i=0; i<n; i++){
      arr[i]='.';
    }
    for(int i=0; i<n; i++){
      if(s[i]=='G'){
        if(abs(curg-i)>k){
          if(i+k<n){
            curg=i+k;
          }
          else{
            curg=n-1;
          }
          arr[curg]='G';
          total++;
        }
      }
      else if(s[i]=='H'){
        if(abs(curh-i)>k){
          if(i+k<n){
            curh=i+k;
          }
          else{
            curh=n-1;
          }
          arr[curh]='H';
          total++;
        }
      }
    }
    if(curg==n-1 and curh==curg){
      arr[n-2]='G';
      arr[n-1]='H';
    }
    cout << total << '\n';
    for(int i=0; i<n; i++){
      cout << arr[i];
    }
    cout << '\n';
  }
}