#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int n,cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
    n=1000-n;
    cnt+=n/500;
    n%=500;
    cnt+=n/100;
    n%=100;
    cnt+=n/50;
    n%=50;
    cnt+=n/10;
    n%=10;
    cnt+=n/5;
    n%=5;
    cnt+=n;
    cout << cnt;
}