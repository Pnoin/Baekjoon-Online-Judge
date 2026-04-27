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

int a,b,c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> a >> b >> c;
    for(int i=0; i<c; i++){
        if(a/2>=b){
            a--;
        }
        else{
            b--;
        }
    }
    if(a/2<b){
        cout << a/2;
    }
    else{
        cout << b;
    }
}