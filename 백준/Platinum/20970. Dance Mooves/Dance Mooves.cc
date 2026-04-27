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

int n,k,arr[100005]={}, ans[100005]={};
vector <int> v[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for(int i=1; i<=n; i++){
    arr[i]=i;
  }
  for(int i=0; i<k; i++) {
    int x, y;
    cin >> x >> y;
    v[arr[x]].emplace_back(y);
    v[arr[y]].emplace_back(x);
    swap(arr[x], arr[y]);
  }
  for(int i=1; i<=n; i++){
    if (v[i].empty()) {
      v[i].emplace_back(i);
    }
  }
  memset(arr, 0, sizeof(arr));
  for(int i=1; i<=n; i++) {
    set<int> s;
    int cur= i, prv = 0;
    if (arr[cur]) {
      ans[cur] = ans[arr[cur]];
      continue;
    }
    s.emplace(cur);
    while (true) {
      arr[prv] = i;
      if (arr[cur]) {
        break;
      }
      s.insert(v[cur].begin(), v[cur].end());
      prv = cur;
      cur = v[cur].back();
    }
    ans[i] = s.size();
  }
  for(int i=1; i<=n; i++) {
      cout << ans[i] << '\n';
  }
}