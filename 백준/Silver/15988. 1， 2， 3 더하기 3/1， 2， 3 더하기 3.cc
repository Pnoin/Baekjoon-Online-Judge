#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")
using namespace std;
typedef long long int ll;

ll t,dp[1000005]={}, md=1e9+9;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4; i<=1000000; i++){
		dp[i]=(dp[i-3]+dp[i-2]+dp[i-1])%md;
	}
	cin >> t;
	for(int i=0; i<t; i++){
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}