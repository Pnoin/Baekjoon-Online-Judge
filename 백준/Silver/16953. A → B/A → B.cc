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

int n,m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  int cnt=0;
  while(true){
    if(m<n){
      cout << -1;
      return 0;
    }
    if(m==n){
      cout << cnt+1;
      return 0;
    }
    if(m%2==1 && m%10!=1){
      cout << -1;
      return 0; 
    }
    if(m%10==1){
      m/=10;
      cnt++;
    }
    else if(m%2==0){
      m/=2; 
      cnt++;
    }
  }
}