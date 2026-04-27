#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <set>
using namespace std;
#pragma GCC optimize ("O3")
typedef pair<int,int> PII;

set <string, greater<string>> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string q,w;
    cin >> q >> w;
    if(w=="enter"){
      s.insert(q);
    }
    else{
      s.erase(q);
    }
  }
  for(auto i:s){
    cout << i << "\n";
  }
}