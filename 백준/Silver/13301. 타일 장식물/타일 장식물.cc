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

ll n,dp[105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[1]=4;
    dp[2]=6;
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    cout << dp[n];
}