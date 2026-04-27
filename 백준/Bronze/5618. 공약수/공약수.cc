#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,a,b,c;

int gcd(int x, int y){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n==2){
        cin >> a >> b;
        int gc=gcd(max(a,b),min(a,b));
        for(int i=1; i<=gc; i++){
            if(gc%i==0){
                cout << i << '\n';
            }
        }
    }
    else{
        cin >> a >> b >> c;
        int gc=gcd(max(a,b),min(a,b));
        int gc2=gcd(max(gc,c),min(gc,c));
        for(int i=1; i<=gc2; i++){
            if(gc2%i==0){
                cout << i << '\n';
            }
        }
    }
}