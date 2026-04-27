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

int n, dp[10005][3]={}, arr[10005]={};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	dp[1][0]=0;
	dp[1][1]=arr[1];
	dp[1][2]=arr[1];
	dp[2][0]=max(max(dp[1][0],dp[1][1]),dp[1][2]);
	dp[2][1]=dp[1][0]+arr[2];
	dp[2][2]=dp[1][1]+arr[2];
	for(int i=3; i<=n; i++){
		dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		dp[i][1]=dp[i-1][0]+arr[i];
		dp[i][2]=dp[i-1][1]+arr[i];
	}
	cout << max(max(dp[n][0],dp[n][1]),dp[n][2]);
}