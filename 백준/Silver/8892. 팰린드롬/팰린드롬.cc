#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool check(string x){
  for(int i=0; i<x.size()/2; i++){
    if(x[i]==x[x.size()-i-1]){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int k, cnt=0;
    cin >> k;
    vector <string> s;
    string a;
    for(int j=0; j<k; j++){
      cin >> a;
      s.push_back(a);
    }
    for(int j=0; j<k; j++){
      for(int q=0; q<k; q++){
        if(j==q){
          continue;
        }
        if(check(s[j]+s[q])){
          cout << s[j] << s[q] << "\n";
          cnt++;
          break;
        }
      }
      if(cnt==1){
        break;
      }
    }
    if(cnt==0){
      cout << 0 << "\n";
    }
  }
}