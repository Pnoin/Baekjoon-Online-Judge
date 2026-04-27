#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;
const double PI = acos(-1); 

int x, n, dp[1000005]={}, arr[105]={};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> x >> n;
  for(int i=0; i<x; i++){
    cin >> arr[i];
  }
  fill(dp, dp+n+1, -1);
  sort(&arr[0], &arr[x]);
  for(int i=1; i<=n; i++){
    for(int j=0; j<x; j++){
      if(i<arr[j]){
        break;
      }
      else if(i==arr[j]){
        dp[i]=1;
        break;
      }
      else{
        if(dp[i-arr[j]]==-1){
          continue;
        }
        else{
          if(dp[i]==-1){
            dp[i]=dp[i-arr[j]]+dp[arr[j]];
          }
          else{
            dp[i]=min(dp[i],dp[i-arr[j]]+dp[arr[j]]);
          }
        }
      }
    }
  }
  cout << dp[n];
}