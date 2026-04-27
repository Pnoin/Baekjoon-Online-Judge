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

int n,k,arr[105]={};
ll dp[100005]={1,};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=arr[i]; j<=k; j++){
			dp[j]+=dp[j-arr[i]];
		}
	}
	cout << dp[k];
}