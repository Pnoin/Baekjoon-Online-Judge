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

ll n,dp[1000005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[0]=1;
    dp[1]=2;
    for(int i=2; i<n; i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=15746;
    }
    cout << dp[n-1];
}