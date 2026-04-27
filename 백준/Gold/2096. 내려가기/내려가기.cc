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

int n,dp[5]={},dp2[5]={};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0; i<3; i++){
    cin >> dp[i];
    dp2[i]=dp[i];
  }
  int a,b,c,temp0,temp1,temp2,temp00,temp11,temp22; 
  for(int i=0; i<n-1; i++){
    cin >> a >> b >> c;
    temp0=max(dp[0]+a, dp[1]+a);
    temp1=max(max(dp[0]+b, dp[1]+b), dp[2]+b);
    temp2=max(dp[1]+c, dp[2]+c);
    temp00=min(dp2[0]+a, dp2[1]+a);
    temp11=min(min(dp2[0]+b, dp2[1]+b), dp2[2]+b);
    temp22=min(dp2[1]+c, dp2[2]+c);
    dp[0]=temp0;
    dp[1]=temp1;
    dp[2]=temp2;
    dp2[0]=temp00;
    dp2[1]=temp11;
    dp2[2]=temp22;
  }
  sort(&dp[0],&dp[3]);
  sort(&dp2[0],&dp2[3]);
  cout << dp[2] << ' ' << dp2[0];
}
