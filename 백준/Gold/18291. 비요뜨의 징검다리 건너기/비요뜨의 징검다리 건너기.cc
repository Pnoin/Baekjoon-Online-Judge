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

ll t,n,md=1e9+7;

ll Pow(ll num, ll ind){
    ll temp=1;
    while(true){
        if(ind==0){
            break;
        }
        if(ind%2==1){
            temp*=num;
            temp%=md;
        }
        num*=num;
        num%=md;
        ind/=2;
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        if(n==1){
            cout << 1 << '\n';
        }
        else{
            cout << Pow(2,n-2) << '\n';
        }
    }
}