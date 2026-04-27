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

int n,arr[505][505]={};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int cnt=0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=n; i>1; i--){
    for(int j=1; j<=i; j++){
      arr[i-1][j] += max(arr[i][j],arr[i][j+1]);
    }
  }
  cout << arr[1][1];
}