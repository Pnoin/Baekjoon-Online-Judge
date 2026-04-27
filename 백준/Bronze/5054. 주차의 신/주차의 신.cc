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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        int n,mx=0,mn=1e9,total=0;
        cin >> n;
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            mx=max(mx,num);
            mn=min(mn,num);
        }
        cout << 2*(mx-mn) << '\n';
    }
}