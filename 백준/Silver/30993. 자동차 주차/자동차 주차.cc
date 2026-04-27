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
typedef long double ld;
typedef complex<double> cpx;
typedef __float128 lf;
const ld PI=3.14159265358979323846264338327950288419716939937510Q;

int n,a,b,c;

ll fac(int x){
    ll total=1;
    for(int i=1; i<=x; i++){
        total*=i;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b >> c;
    cout << fac(n)/(fac(a)*fac(b)*fac(c));
}