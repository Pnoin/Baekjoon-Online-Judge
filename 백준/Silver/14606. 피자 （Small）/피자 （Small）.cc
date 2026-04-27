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

int n,dp[15]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp[1]=0;
    dp[2]=1;
    for(int i=3; i<=n; i++){
        dp[i]=((i/2)*(i-(i/2)))+dp[i/2]+dp[i-(i/2)];
    }
    cout << dp[n];
}