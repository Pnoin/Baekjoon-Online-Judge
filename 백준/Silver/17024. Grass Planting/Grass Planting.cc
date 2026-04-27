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
const double PI = acos(-1);
typedef complex<double> cpx;

int n,arr[100005]={};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n-1; i++){
    int x,y;
    cin >> x >> y;
    arr[x]++;
    arr[y]++;
  }
  int mx=0;
  for(int i=1; i<=n; i++){
    mx=max(mx,arr[i]);
  }
  cout << mx+1;
}