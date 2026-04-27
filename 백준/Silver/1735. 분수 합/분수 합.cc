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

int a,b,x,y;

int gcd(int x, int y){
    if(x<y){
        swap(x,y);
    }
    int z;
    while(true){
        if(y==0){
            break;
        }
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int lcm(int x, int y){
    int GCD=gcd(x,y);
    return GCD*(x/GCD)*(y/GCD);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> x >> y;
    int temp=lcm(b,y),temp2=gcd(b,y);
    a*=(y/temp2);
    x*=(b/temp2);
    cout << (a+x)/gcd(a+x,temp) << ' ' << temp/gcd(a+x,temp);
}