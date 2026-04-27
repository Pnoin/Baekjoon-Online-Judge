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
  string s;
  for(int i=0; i<n; i++){
    cin >> s;
    m[s]++;
  }
  for(int i=0; i<n-1; i++){
    cin >> s;
    m[s]--;
  }
  for(auto i:m){
    if(i.second!=0){
      cout << i.first;
      return 0;
    }
  }
}