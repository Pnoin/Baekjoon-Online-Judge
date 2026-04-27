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

int n;
double a,b,total;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    total=a*1000/b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        total=min(total,a*1000/b);
    }
    cout << fixed;
    cout.precision(2);
    cout << total;
}