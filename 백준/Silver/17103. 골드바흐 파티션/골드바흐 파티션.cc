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

int arr[1000005]={},n,t;
vector <int> v;

void sieve(int n){
    memset(arr,0,sizeof(arr));
    v.clear();
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            for(int j=i*2; j<=n; j+=i){
                arr[j]=1;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            v.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    sieve(1000000);
    for(int i=0; i<t; i++){
        int cnt=0;
        cin >> n;
        for(int j=0; j<v.size(), v[j]<=n/2; j++){
            if(binary_search(v.begin(), v.end(),n-v[j])){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}