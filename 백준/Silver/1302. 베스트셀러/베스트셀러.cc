#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <map>
using namespace std;
#pragma GCC optimize ("O3")
typedef pair<int,int> PII;

map <string, int> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s; 
    m[s]++;
  }
  int mx=0;
  for(auto i:m){
    mx=max(mx,i.second);
  }
  for(auto i:m){
    if(i.second==mx){
      cout << i.first;
      return 0;
    }
  }
}