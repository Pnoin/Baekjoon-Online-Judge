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

int n,arr[20]={},brr[20]={},crr[20]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i] >> brr[i];
    }
    for(int i=n-1; i>=0; i--){
        if(arr[i]>n-i){
            crr[i]=crr[i+1];
        }
        else{
            crr[i]=max(brr[i]+crr[i+arr[i]],crr[i+1]);
        }
    }
    cout << crr[0];
}