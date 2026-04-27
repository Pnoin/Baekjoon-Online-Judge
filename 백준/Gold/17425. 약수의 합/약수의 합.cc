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

ll t, arr[1000005]={};

void sieve(){
    for(int i=1; i<=1000000; i++){
        for(int j=i; j<=1000000; j+=i){
            arr[j]+=i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    for(int i=1; i<=1000000; i++){
        arr[i]+=arr[i-1];
    }
    cin >> t;
    for(int i=0; i<t; i++){
        int num;
        cin >> num;
        cout << arr[num] << '\n';
    }
}