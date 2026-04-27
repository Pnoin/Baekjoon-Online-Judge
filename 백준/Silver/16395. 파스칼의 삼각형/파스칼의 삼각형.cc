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

int n,k,dp[35][35]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j]=1;
        }
    }
    for(int i=2; i<n; i++){
        for(int j=1; j<i; j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    cout << dp[n-1][k-1];
} 