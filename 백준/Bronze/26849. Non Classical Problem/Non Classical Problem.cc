#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

int n;
ld x,y,total=0,mx=0,mn=2e9+1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        mx=max(mx,x/y);
        mn=min(mn,x/y);
        total+=x/y;
    }
    cout << fixed;
    cout.precision(11);
    cout << mn << ' ' << mx << ' ' << total;
}