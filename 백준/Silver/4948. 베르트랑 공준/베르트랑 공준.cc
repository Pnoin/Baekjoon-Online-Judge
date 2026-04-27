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

int arr[300000]={},n;

int sieve(int n){
    int cnt=0;
    memset(arr,0,sizeof(arr));
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            for(int j=i*2; j<=n; j+=i){
                arr[j]=1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        cout << sieve(2*n)-sieve(n) << '\n';
    }
}