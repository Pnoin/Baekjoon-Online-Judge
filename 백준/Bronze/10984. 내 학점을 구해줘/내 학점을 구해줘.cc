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

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> t;
    cout << fixed;
    cout.precision(1);
    for(int i=0; i<t; i++){
        int n;
        double total=0,cnt=0;
        cin >> n;
        for(int j=0; j<n; j++){
            double x,y;
            cin >> x >> y;
            total+=x;
            cnt+=x*y;
        }
        cout << (int)total << ' ' << cnt/total << '\n';
    }
}