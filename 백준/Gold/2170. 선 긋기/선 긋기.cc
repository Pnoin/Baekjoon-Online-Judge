#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#pragma GCC optimize ("O3")
typedef pair<int,int> PII;

vector <PII> v;

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