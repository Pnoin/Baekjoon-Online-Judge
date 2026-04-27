#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

ll n,dp[100005]={},arr[100005]={},total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0]=arr[0];
    for(int i=1; i<n; i++){
        dp[i]=dp[i-1]+arr[i];
    }
    for(int i=0; i<n-1; i++){
		total+=(dp[n-1]-dp[i])*arr[i];
	}
    cout << total;
}