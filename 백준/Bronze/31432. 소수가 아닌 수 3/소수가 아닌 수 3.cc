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

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << "YES" << '\n';
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num<2){
            cout << num;
            return 0;
        }
        else{
            cout << num*11;
            return 0;
        }
    }
}