#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

vector <pair<int,int>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, total=0;
  cin >> n;
  for(int i=0; i<n; i++){
    int a,b;
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }
  sort(v.begin(), v.end());
  int lo=v[0].first, hi=v[0].second;
  for(int i=0; i<n; i++){
    if(hi < v[i].first){
      total+=hi-lo;
      lo=v[i].first;
    }
    hi=max(hi,v[i].second);
  }
  total+=hi-lo;
  cout << total;
}
