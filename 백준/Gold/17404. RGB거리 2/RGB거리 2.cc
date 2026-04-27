#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;
typedef pair <int,int> PII;

int n,arr[1005][5]={},dp[1005][5]={},ans=1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i++){
    for(int j=0; j<3; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<3; i++){
	for(int j=0; j<3; j++){
		if(i==j){
            dp[1][j]=arr[1][j];
        }
		else{
            dp[1][j]=1e9;
        }
	}
    for(int j=2; j<=n; j++){
        dp[j][0]=arr[j][0]+min(dp[j-1][1], dp[j-1][2]);
        dp[j][1]=arr[j][1]+min(dp[j-1][0], dp[j-1][2]);
        dp[j][2]=arr[j][2]+min(dp[j-1][1], dp[j-1][0]);
    }
    for(int j=0; j<3; j++){
        if(i!=j){
            ans=min(ans, dp[n][j]);	
        }		
    }
  }
  cout << ans;
}