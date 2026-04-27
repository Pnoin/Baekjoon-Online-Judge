#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

vector <int> v;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int x; 
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int start=0, end=v.size()-1, min=2e9, final=0; 
  while(true){
    if(start>=end){
      break;
    }
    if(abs(v[start]+v[end])<min){
      min=abs(v[start]+v[end]);
      final=v[start]+v[end];
    }
    if(v[start]+v[end]==0){
      break;
    }
    else if(v[start]+v[end]>0){
      end--;
    }
    else{
      start++;
    }
  }
  cout << final;
}