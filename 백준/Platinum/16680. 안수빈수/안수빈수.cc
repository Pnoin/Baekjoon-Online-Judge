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

int t,mp=1e9-1;
ll n;
/*
ll digit_sum(ll temp){
    ll total=0;
    while(true){
        if(temp==0){
            break;
        }
        total+=temp%10;
        temp/=10;
    }
    return total;
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        cout << n*mp << '\n';
    }
    /*
        1,253,000,000,000 - 1,253 = 1,252,999,998,747 (81)
        99,999,999,000,000,000 - 99,999,999 = 99,999,998,900,000,001
    */
}