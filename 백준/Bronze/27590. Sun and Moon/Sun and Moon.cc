#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

int a,b,c,d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c >> d;
    a=abs(a-b);
    c=abs(c-d);
    while(true){
        if(a==c){
            break;
        }
        if(a<c){
            a+=b;
        }
        else{
            c+=d;
        }
    }
    cout << a;
}