#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;

int n,dp[1550][3]={},md=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[1][0]=0;
    dp[1][1]=0;
    dp[1][2]=1;
    dp[2][0]=1;
    dp[2][1]=1;
    dp[2][2]=0; 
    for(int i=3; i<=n; i++){
        dp[i][0]=(dp[i-1][2]+dp[i-1][1])%md;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%md;
		dp[i][2]=(dp[i-1][1]+dp[i-1][0])%md;
    }
    cout << dp[n][0];
}