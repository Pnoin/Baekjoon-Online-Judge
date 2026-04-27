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

int a,b,c,d,e;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c >> d >> e;
    if(e<=30){
        cout << a << ' ';
    }
    else{
        cout << (e-30)*21*b+a << ' ';
    }
    if(e<=45){
        cout << c;
    }
    else{
        cout << (e-45)*21*d+c;
    }
}