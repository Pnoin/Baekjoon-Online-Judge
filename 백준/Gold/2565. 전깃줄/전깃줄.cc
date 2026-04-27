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

int n, dp[105]={};
pair <int,int> arr[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr+1, arr+1+n);
	dp[1]=1;
	for(int i=2; i<=n; i++){
		for(int j=i; j>0; j--){
			if(arr[i].second>arr[j].second){
				dp[i]=max(dp[i],dp[j]);
			}
		}
		dp[i]++;
	}
	sort(dp+1, dp+n+1);
	cout << n-dp[n];
}