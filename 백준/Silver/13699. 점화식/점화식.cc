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

ll n,dp[45]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i]+=dp[i-j]*dp[j-1];
        }
    }
    cout << dp[n];
}