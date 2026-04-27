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

int n, dp[305]={}, arr[305]={};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	dp[3]=max(arr[1]+arr[3],arr[2]+arr[3]);
	for(int i=4; i<=n; i++){
		dp[i]=max(dp[i-2]+arr[i],arr[i-1]+arr[i]+dp[i-3]);
	}
	cout << dp[n];
}