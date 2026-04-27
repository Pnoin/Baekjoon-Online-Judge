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

int n,m,dp[1000005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=n+1; i<=m; i++){
        if(i>=n*2 && i%2==0){
            dp[i]=min(dp[i-1]+1,dp[i/2]+1);
        }
        else{
            dp[i]=dp[i-1]+1;
        }
    }
    cout << dp[m];
}