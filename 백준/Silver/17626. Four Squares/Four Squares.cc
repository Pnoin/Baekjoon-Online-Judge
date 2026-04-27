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

int n,dp[50005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[0]=0;
    for(int i=1; i<=n; i++){
        dp[i]=dp[i-1]+1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sqrt(i); j++){
            dp[i]=min(dp[i-j*j]+1,dp[i]);
        }
    }
    cout << dp[n];
}