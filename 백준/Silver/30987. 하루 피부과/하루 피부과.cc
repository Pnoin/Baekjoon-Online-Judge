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

int x1,x2,a,b,c,d,e;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x1 >> x2 >> a >> b >> c >> d >> e;
    b-=d;
    c-=e;
    a/=3;
    b/=2;
    ld ff, ss;
    ff=(a*x1*x1*x1)+(b*x1*x1)+(c*x1);
    ss=(a*x2*x2*x2)+(b*x2*x2)+(c*x2);
    cout << ss-ff;
}