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

int n,a,b,c,d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> a >> b >> c >> d >> n;
    int cnt=a*n,temp=0;
    if(c>=n){
        temp=b;
    }
    else{
        temp=((n-c)*d)+b;
    }
    cout << min(temp,cnt);
}