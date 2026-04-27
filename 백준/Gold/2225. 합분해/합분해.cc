#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;

int n,k,dp[205][205]={}, md=1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        dp[i][1]=1;
    }
    for(int i=1; i<=k; i++){
        dp[1][i]=i;
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%md;
        }
    }
    cout << dp[n][k];
}