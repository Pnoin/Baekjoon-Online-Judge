#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n,arr[10]={};
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
  for(int i=1; i<=n; i++){
    string s;
    cin >> s;
    for(int j=0; j<5; j++){
      if(s[j]=='Y'){
        arr[j+1]++;
      }
    }
  }
  int mx=0;
  for(int i=1; i<=5; i++){
    if(arr[i]>mx){
      mx=arr[i];
    }
  }
  for(int i=1; i<=5; i++){
    if(arr[i]==mx){
      v.push_back(i);
    }
  }
  if(v.size()>1){
    for(int i=0; i<v.size(); i++){
      cout << v[i];
      if(i<v.size()-1){
        cout << ',';
      }
    }
  }
  else{
    cout << v[0];
  }
}
