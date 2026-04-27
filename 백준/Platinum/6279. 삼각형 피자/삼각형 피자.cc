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
typedef complex<double> cpx;

int t,n;
ll arr[16]={1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> n;
        cout << "Case #" << i << ": " << arr[n-1] << '\n';
    }
}