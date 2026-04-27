#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const double PI = acos(-1); 

ld x,y,z,a,b,c;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    cin >> x >> y >> z;
    a=(x+y-z)/2;
    b=x-a;
    c=y-a;
    if(a<=0 || b<=0 || c<=0){
        cout << -1;
    }
    else{
        cout << 1 << '\n';
        cout << fixed;
        cout.precision(1);
        cout << a << ' ' << b << ' ' << c;
    }
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << duration << "초";
    */
}