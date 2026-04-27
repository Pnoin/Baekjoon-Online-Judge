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

int n, arr[100005]={}, dp[100005]={}, mx;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
    mx=arr[1];
	dp[1]=arr[1];
    for(int i=2; i<=n; i++){
        dp[i]=max(dp[i-1]+arr[i], arr[i]);
        mx=max(dp[i], mx);
    }
    cout << mx;
}