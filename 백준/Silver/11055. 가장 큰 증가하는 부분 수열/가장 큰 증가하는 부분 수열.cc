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

int n, arr[1005]={}, dp[1005]={};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	dp[1]=arr[1];
	for(int i=2; i<=n; i++){
		if(arr[i]==arr[i-1]){
			dp[i]=dp[i-1];
		}
		else{
			for(int j=i; j>0; j--){
				if(arr[i]>arr[j]){
					dp[i]=max(dp[i],dp[j]);
				}
			}
			dp[i]+=arr[i];
		}
	}
	sort(dp+1, dp+n+1);
	cout << dp[n];
}