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

int x,n,a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a<b){
            if(x+a-2*(b-1)>0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(a>b){
            if(x+b+1-2*(a-1)>0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            cout << 1 << '\n';
        }
    }
}