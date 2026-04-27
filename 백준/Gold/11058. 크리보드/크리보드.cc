#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;

int n;
ll dp[105]={};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n; 
  for(int i=1; i<=6; i++){
    dp[i]=i;
  }
  for(int i=7; i<=n; i++){
    ///1~3 x,x,x,a,c,v,v,a,c,v,v
    /*for(int i=0; i<3; i++){
      dp[i]=max(dp[])
    }
    */
    dp[i]=max(max(dp[i-5]*4,dp[i-4]*3),dp[i-3]*2);
  }
  cout << dp[n];
}

