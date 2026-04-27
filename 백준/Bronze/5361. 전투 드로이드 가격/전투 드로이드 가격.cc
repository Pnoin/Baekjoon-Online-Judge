#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        double a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        cout << fixed; 
        cout.precision(2);
        cout << '$' << 350.34*a+230.90*b+190.55*c+125.30*d+180.90*e << '\n';
    }
}