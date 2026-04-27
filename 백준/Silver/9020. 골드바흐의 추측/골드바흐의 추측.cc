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
typedef complex<double> cpx;
const double PI = acos(-1); 

int t,n,arr[10005]={};

void sieve(){
    for(int i=2; i<10000; i++){
        if(arr[i]==0){
            for(int j=2*i; j<=10000; j+=i){
                arr[j]=1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    sieve();
    for(int test=0; test<t; test++){
        cin >> n;
        for(int i=n/2; i>=2; i--){
            if(arr[i]==0 && arr[n-i]==0){
                cout << min(i,n-i) << ' ' << max(i,n-i) << '\n';
                break;
            }
        }
    }
}