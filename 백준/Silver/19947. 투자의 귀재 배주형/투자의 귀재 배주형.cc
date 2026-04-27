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

ll n,m,dp[15]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dp[1]=n;
    for(int i=2; i<=m+1; i++){
        if(i<4){
            dp[i]=dp[i-1]*1.05;
        }
        else if(i==4 || i==5){
            dp[i]=max(dp[i-3]*1.2,dp[i-1]*1.05);
        }
        else{
            dp[i]=max(max(dp[i-3]*1.2,dp[i-1]*1.05),dp[i-5]*1.35);
        }
    }
    cout << dp[m+1];
}