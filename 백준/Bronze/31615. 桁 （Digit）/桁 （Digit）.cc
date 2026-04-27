#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

int a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> a >> b;
    cout << (int)log10(a+b)+1;
}