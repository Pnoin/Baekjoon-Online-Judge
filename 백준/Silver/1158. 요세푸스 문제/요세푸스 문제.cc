#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#pragma GCC optimize ("O3")
typedef long long int ll;
using namespace std;

queue <int> q;
vector <int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, s;
  cin >> n >> s;
  for(int i=1; i<=n; i++){
    q.push(i);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<s-1; j++){
      q.push(q.front());
      q.pop();
    }
    v.push_back(q.front());
    q.pop();
  }
  cout << '<';
  for(int i=0; i<n; i++){
    if(i<n-1){
      cout << v[i] << ", ";
    }
    else{
      cout << v[i] << '>';
    }
  }
}